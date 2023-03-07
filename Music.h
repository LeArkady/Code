#pragma once
#include <vector>
using namespace std;






//Класс: музыкальный звук
enum note
{
	C = 0,
	Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B
};

//Функция преобразует звук в строку с названием ноты
CString note_to_cstring(note input)
{
	switch (input)
	{
	case(C): {return _T("C"); break; }
	case(Db): {return _T("C#"); break;}
	case(D): {return _T("D"); break; }
	case(Eb): {return _T("D#"); break; }
	case(E): {return _T("E"); break; }
	case(F): {return _T("F"); break; }
	case(Gb): {return _T("F#"); break; }
	case(G): {return _T("G"); break; }
	case(Ab): {return _T("G#"); break; }
	case(A): {return _T("A"); break; }
	case(Bb): {return _T("A#"); break; }
	case(B): {return _T("B"); break; }
	}
}
//Эта функция работает аналогично, но может принимать в качестве аргумента паузу, представляемую числом "-1"
CString note_to_cstring(int input)
{
	switch (input)
	{
	case(-1): {return _T(" "); break; }
	case(0): {return _T("C"); break; }
	case(1): {return _T("C#"); break; }
	case(2): {return _T("D"); break; }
	case(3): {return _T("D#"); break; }
	case(4): {return _T("E"); break; }
	case(5): {return _T("F"); break; }
	case(6): {return _T("F#"); break; }
	case(7): {return _T("G"); break; }
	case(8): {return _T("G#"); break; }
	case(9): {return _T("A"); break; }
	case(10): {return _T("A#"); break; }
	case(11): {return _T("B"); break; }
	}
}




//Класс: уровень диссонантности
//Он представляет собой меру диссонантности интервалов(консонансы < малые септимы и большие ноны < большие септимы < тритоны), которые могут образовываться между аккордовым звуком и звуком из мелодии
enum stench
{
	chord_tones,
	pentatonic,
	sevenths,
	tritones
};




//Класс: Тип Лада. Тип лада представлен набором интервалов(в полутонах), на которые отстоят ступени лада.
class scale_type
{
	unsigned int amount;
	vector<unsigned int> degrees;

	friend class scale;
public:
	scale_type()
	{
		(this->amount) = 0;
	}
	scale_type(unsigned int* father, unsigned int length)
	{
		(this->amount) = length;
		for (unsigned int i = 0; i < length; i++)
		{
			this->degrees.push_back(father[i]);
		}
	}

	bool operator==(const scale_type& other)
	{
		if (this->amount != other.amount) { return false; }
		for (unsigned int i = 0; i < this->amount; i++)
		{
			if (this->degrees[i] != other.degrees[i]) { return false; }
		}
		return true;
	}
	bool operator!=(const scale_type& other)
	{
		return !(this[0] == other);
	}
};




//Далее следуют типы ладов, с которыми программа будет оперировать для контроля за возникающими диссонансами
//Лады расставлены в порядке возрастания уровня диссонантности интервалов между аккордовым звуком и звуком из мелодии


//уровень - Консонансы
//"Лад", представленный лишь аккордовыми звуками(мажорного трезвучия):
unsigned  int major[3] = { 0, 4, 7 };
scale_type Maj(major, 3);
//"Лад", представленный лишь аккордовыми звуками(минорного трезвучия):
unsigned  int minor[3] = { 0, 3, 7 };
scale_type Min(minor, 3);


//уровень - Малые септимы и большие ноны
//Мажорная пентатоника:
unsigned  int majpent[5] = { 0, 2, 4, 7, 9 };
scale_type MajPent(majpent, 5);
//Минорная пентатоника:
unsigned  int minpent[5] = { 0, 3, 5, 7, 10 };
scale_type MinPent(minpent, 5);


//уровень - Большие септимы
//Мажорная пентатоника + восходящий вводный тон(7 ступень ионийского лада)
unsigned  int majhex[6] = { 0, 2, 4, 7, 9, 11 };
scale_type MajHex(majhex, 6);
//Минорная пентатоника + нисходящий вводный тон(2 тупень эолийского лада)
unsigned  int minhex[6] = { 0, 2, 3, 5, 7, 10 };
scale_type MinHex(minhex, 6);


//уровень - Тритоны:
//Лидийский лад
unsigned  int lyd[7] = { 0,2, 4, 6, 7, 9, 11 };
scale_type Lydian(lyd, 7);
//Дорийский лад
unsigned  int dor[7] = { 0, 2, 3, 5, 7, 9, 10 };
scale_type Dorian(dor, 7);

///////////////////////////////////////////////////////////////////////




//Класс: Лад
//Представлен лад тоникой и типом лада
class scale
{
public:
	scale_type type;
	note root;

	scale()
	{
		(this->root) = C;
		(this->type) = scale_type();
	}
	scale(note t, scale_type father)
	{
		(this->root) = t;
		(this->type) = father;
	}

	bool check(note t)
	{
		int r = (this->root);
		int p = t;

		int q;
		for (unsigned int i = 0; i < (this->type.amount); i++)
		{
			q = (this->type).degrees[i];
			if ((p - r - q) % 12 == 0)
			{
				return true;
			}
		}
		return false;
	}
	bool check(int p)
	{
		int r = (this->root);
		if (p < 0) { return true; }

		int q;
		for (unsigned int i = 0; i < (this->type.amount); i++)
		{
			q = (this->type).degrees[i];
			if ((p - r - q) % 12 == 0)
			{
				return true;
			}
		}
		return false;
	}


	bool operator==(const scale& other)
	{
		if (this->root != other.root) { return false; }
		if (!(this->type == other.type)) { return false; }
		return true;
	}
	bool operator!=(const scale& other)
	{
		return !(this[0] == other);
	}
};











//Класс: тип аккорда(мажорный, минорный)
enum chord_type
{
	M,
	m
};

//Класс: аккорд.
//Представлен своей тоникой и типом трезвучия
class chord
{
	note root;
	chord_type type;

public:

	chord(note sroot, chord_type stype)
	{
		this->root = sroot;
		this->type = stype;
	}



	bool operator==(const chord& other)
	{
		if (this->root != other.root) { return false; }
		if (this->type != other.type) { return false; }
		return true;
	}
	bool operator!=(const chord& other)
	{
		return !(this[0] == other);
	}

	friend CString chord_to_cstring(chord chord);
};
//Функция преобразует аккорд в строку с названием аккорда
CString chord_to_cstring(chord chord)
{
	CString out = note_to_cstring(chord.root);

	switch (chord.type)
	{
	case(M):
	{
		out += _T(" ");
		break;
	}
	case(m):
	{
		out += _T("m ");
		break;
	}
	}
	return out;
}




//Класс: такт
//Такт включает определенное кол-во четвертных(им определяется длна такта). Каждая четвертная разбивается на 2 восьмых. Именно восьмыми и оперирует программа
//Объект представлен массивом целых чисел(каждый элемент соответствует одной восьмой ноте и хранит в себе ноту либо паузу)
class bar
{
	vector<int> grid;
public:
	unsigned int length;
	bar(unsigned int meter)
	{
		length = meter;
		unsigned int eight_notes_amount = meter * 2;
		for (unsigned int i = 0; i < eight_notes_amount; i++)
		{
			grid.push_back(0);
		}
	}
	bar()
	{
		length = 4;
		for (unsigned int i = 0; i < 8; i++)
		{
			grid.push_back(-1);
		}
	}
	void set_note(unsigned int time, int note)
	{
		if (time < length * 2)
		{
			this->grid[time] = note;
		}
	}
	int get_note(unsigned int time)
	{
		return static_cast<note>(this->grid[time]);
	}
};












//Центральная идея программы: Функция, возвращающая набор трезвучий, которыми можно гармонизовать данный такт, при выбранном уровне диссонантности
vector<chord> posibilities(bar chunk, stench reek)
{
	unsigned int L = chunk.length * 2; //Длина такта в восьмых нотах
	bool fits; //Переменная хранит информацию о том, подходит ли рассматриваемый аккорд к данному такту(в зависимости от допустимых диссонансов)

	vector<chord> bucket; //Здесь хранится список аккордов, подходящих для гармонизации рассматриваемого такта



	chord_type type; //тип рассматриваемых аккордов

	scale the_chord_scale; //Лад, который будет соответствовать рассматриваемому аккорду при выбранном уровне диссонсантности
	//Чтобы аккорд подходил к мелодии, все звуки мелодии должны содержатся в этом ладу




	//Перебор вариантов: мажорные трезвучия
	//Выбирается тип лада в зависимости от уровня диссонантности:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Maj; break; }
	case(pentatonic): {the_chord_scale.type = MajPent; break; }
	case(sevenths): {the_chord_scale.type = MajHex; break; }
	case(tritones): {the_chord_scale.type = Lydian; break; }
	}
	type = M;

	//Процедура перебора вариантов(трезвучий) и проверки звуков на пренадлежность соответствующим им ладам:
	for (unsigned int i = 0; i < 12; i++)
	{
		fits = 1;
		the_chord_scale.root = static_cast<note>(i);
		for (unsigned int j = 0; j < L; j++)
		{
			if (!the_chord_scale.check(chunk.get_note(j)))
			{
				fits = 0;
				break;
			}
		}
		if (fits) { bucket.push_back(chord((the_chord_scale.root), type)); }
	}




	//Перебор вариантов: мажорные трезвучия
	//Выбирается тип лада в зависимости от уровня диссонантности:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Min; break; }
	case(pentatonic): {the_chord_scale.type = MinPent; break; }
	case(sevenths): {the_chord_scale.type = MinHex; break; }
	case(tritones): {the_chord_scale.type = Dorian; break; }
	}
	type = m;

	//Процедура перебора вариантов(аккордов) и проверки звуков на пренадлежность соответствующим им ладам:
	for (unsigned int i = 0; i < 12; i++)
	{
		fits = 1;
		the_chord_scale.root = static_cast<note>(i);
		for (unsigned int j = 0; j < L; j++)
		{
			if (!the_chord_scale.check(chunk.get_note(j)))
			{
				fits = 0;
				break;
			}
		}
		if (fits) { bucket.push_back(chord((the_chord_scale.root), type)); }
	}


	return bucket;
}




//Функция выполняет те же действия, но рассматривает лишь звуки, стоящие на месте ритмически сильных акцентов(сила акцента определяется пользователем). Неакцентированные звуки не будут учитываться
vector<chord> posibilities(bar chunk, stench reek, unsigned int depth)
{
	unsigned int L = chunk.length * 2; //Длина такта в восьмых нотах
	bool fits; //Переменная хранит информацию о том, подходит ли рассматриваемый аккорд к данному такту(в зависимости от допустимых диссонансов)

	vector<chord> bucket; //Здесь хранится список аккордов, подходящих для гармонизации рассматриваемого такта



	chord_type type; //тип рассматриваемых трезвучий

	scale the_chord_scale; //Лад, который будет соответствовать рассматриваемому аккорду при выбранном уровне диссонсантности
	//Чтобы аккорд подходил к мелодии, все ее звуки должны содержатся в этом ладу




	//Перебор вариантов: мажорные трезвучия
	//Выбирается тип лада в зависимости от уровня диссонантности:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Maj; break; }
	case(pentatonic): {the_chord_scale.type = MajPent; break; }
	case(sevenths): {the_chord_scale.type = MajHex; break; }
	case(tritones): {the_chord_scale.type = Lydian; break; }
	}
	type = M;

	//Процедура перебора вариантов(трезвучий) и проверки звуков на пренадлежность соответствующим им ладам:
	for (unsigned int i = 0; i < 12; i++)
	{
		fits = 1;
		the_chord_scale.root = static_cast<note>(i);
		for (unsigned int j = 0; j < L; j++)
		{
			if ((!the_chord_scale.check(chunk.get_note(j))) && (j % depth == 0))
			{
				fits = 0;
				break;
			}
		}
		if (fits) { bucket.push_back(chord((the_chord_scale.root), type)); }
	}




	//Перебор вариантов: минорные трезвучия
	//Выбирается тип лада в зависимости от уровня диссонантности:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Min; break; }
	case(pentatonic): {the_chord_scale.type = MinPent; break; }
	case(sevenths): {the_chord_scale.type = MinHex; break; }
	case(tritones): {the_chord_scale.type = Dorian; break; }
	}
	type = m;

	//Процедура перебора вариантов(трезвучий) и проверки звуков на пренадлежность соответствующим им ладам:
	for (unsigned int i = 0; i < 12; i++)
	{
		fits = 1;
		the_chord_scale.root = static_cast<note>(i);
		for (unsigned int j = 0; j < L; j++)
		{
			if ((!the_chord_scale.check(chunk.get_note(j))) && (j % depth == 0))
			{
				fits = 0;
				break;
			}
		}
		if (fits) { bucket.push_back(chord((the_chord_scale.root), type)); }
	}

	return bucket;
}




//Функция выполняет те же действия, но рассматривает лишь звуки перед достаточно длинной паузой, измеряемой в восьмых(повторение звука приравнивается к паузе)
//Это тоже позволяет учесть акцентированность потенциальных диссонансов(но уже в смысле разрешенности). Быстро разрешенные диссонансы(длящиеся не дольше заданного времени) не будут учитываться
vector<chord> posibilities(bar chunk, stench reek, unsigned int depth, unsigned int pause)
{
	unsigned int L = chunk.length * 2; //Длина такта в восьмых
	bool fits; //Переменная хранит информацию о том, подходит ли рассматриваемый аккорд к данному такту(в зависимости от допустимых диссонансов)

	vector<chord> bucket; //Здесь хранится список аккордов, подходящих для гармонизации рассматриваемого такта



	chord_type type; //тип рассматриваемых трезвучий

	scale the_chord_scale; //Лад, который будет соответствовать рассматриваемому аккорду при выбранном уровне диссонсантности
	//Чтобы аккорд подходил к мелодии, все звуки должны содержатся в этом ладу




	//Здесь составляется таблица условной "длительности" каждой ноты такта
	//Каждой паузе соответствует число "0"
	//Каждой ноте соответствует кол-во восьмых, в течении к-рых этот ВЫСОТА ЗВУКА НЕ МЕНЯЕТСЯ
	//(т. е. расстояние между первым вхождением этой ноты в такт и первым вхождением следующей ноты)
	//При подсчете расстояния учитываются как паузы после рассматриваемой ноты, так и повторения этой ноты 
	vector<unsigned int> lengths;
	unsigned int t;
	for (unsigned int i = 0; i < L; i++)
	{
		t = 0;
		if (chunk.get_note(i) != -1)
		{
			t++;
			while (1)
			{
				if ((i + t == L) || (chunk.get_note(i + t) != -1) && (chunk.get_note(i + t) != chunk.get_note(i))) { break; }
				t++;
			}
		}
		lengths.push_back(t);
	}
	



	//Перебор вариантов: мажорные трезвучия
	//Выбирается тип лада в зависимости от уровня диссонантности:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Maj; break; }
	case(pentatonic): {the_chord_scale.type = MajPent; break; }
	case(sevenths): {the_chord_scale.type = MajHex; break; }
	case(tritones): {the_chord_scale.type = Lydian; break; }
	}
	type = M;

	//Процедура перебора вариантов(трезвучий) и проверки нот на пренадлежность соответствующим им ладам:
	for (unsigned int i = 0; i < 12; i++)
	{
		fits = 1;
		the_chord_scale.root = static_cast<note>(i);
		for (unsigned int j = 0; j < L; j++)
		{
			if ((!the_chord_scale.check(chunk.get_note(j))) && (j % depth == 0) && (lengths[j] >= pause))
			{
				fits = 0;
				break;
			}
		}
		if (fits) { bucket.push_back(chord((the_chord_scale.root), type)); }
	}




	//Перебор вариантов: минорные трезвучия
	//Выбирается тип лада в зависимости от уровня диссонантности:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Min; break; }
	case(pentatonic): {the_chord_scale.type = MinPent; break; }
	case(sevenths): {the_chord_scale.type = MinHex; break; }
	case(tritones): {the_chord_scale.type = Dorian; break; }
	}
	type = m;

	//Процедура перебора вариантов(трезвучий) и проверки нот на пренадлежность соответствующим им ладам:
	for (unsigned int i = 0; i < 12; i++)
	{
		fits = 1;
		the_chord_scale.root = static_cast<note>(i);
		for (unsigned int j = 0; j < L; j++)
		{
			if ((!the_chord_scale.check(chunk.get_note(j))) && (j % depth == 0) && (lengths[j] >= pause))
			{
				fits = 0;
				break;
			}
		}
		if (fits) { bucket.push_back(chord((the_chord_scale.root), type)); }
	}

	return bucket;
}












//Вспомогательная функция для обработки информации, получаемой от раскрывающегося списка. Функция преобразует номер выбранной опции в ноту(0, 1, ... , 11) или паузу(-1)
int option_to_note(int input)
{
	if ((0 <= input) && (input <= 12))
	{
		return (11 - input);
	}
	return -1;
}