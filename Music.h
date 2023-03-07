#pragma once
#include <vector>
using namespace std;






//�����: ����������� ����
enum note
{
	C = 0,
	Db, D, Eb, E, F, Gb, G, Ab, A, Bb, B
};

//������� ����������� ���� � ������ � ��������� ����
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
//��� ������� �������� ����������, �� ����� ��������� � �������� ��������� �����, �������������� ������ "-1"
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




//�����: ������� ��������������
//�� ������������ ����� ���� �������������� ����������(���������� < ����� ������� � ������� ���� < ������� ������� < �������), ������� ����� �������������� ����� ���������� ������ � ������ �� �������
enum stench
{
	chord_tones,
	pentatonic,
	sevenths,
	tritones
};




//�����: ��� ����. ��� ���� ����������� ������� ����������(� ���������), �� ������� ������� ������� ����.
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




//����� ������� ���� �����, � �������� ��������� ����� ����������� ��� �������� �� ������������ ������������
//���� ����������� � ������� ����������� ������ �������������� ���������� ����� ���������� ������ � ������ �� �������


//������� - ����������
//"���", �������������� ���� ����������� �������(��������� ���������):
unsigned  int major[3] = { 0, 4, 7 };
scale_type Maj(major, 3);
//"���", �������������� ���� ����������� �������(��������� ���������):
unsigned  int minor[3] = { 0, 3, 7 };
scale_type Min(minor, 3);


//������� - ����� ������� � ������� ����
//�������� �����������:
unsigned  int majpent[5] = { 0, 2, 4, 7, 9 };
scale_type MajPent(majpent, 5);
//�������� �����������:
unsigned  int minpent[5] = { 0, 3, 5, 7, 10 };
scale_type MinPent(minpent, 5);


//������� - ������� �������
//�������� ����������� + ���������� ������� ���(7 ������� ���������� ����)
unsigned  int majhex[6] = { 0, 2, 4, 7, 9, 11 };
scale_type MajHex(majhex, 6);
//�������� ����������� + ���������� ������� ���(2 ������ ���������� ����)
unsigned  int minhex[6] = { 0, 2, 3, 5, 7, 10 };
scale_type MinHex(minhex, 6);


//������� - �������:
//��������� ���
unsigned  int lyd[7] = { 0,2, 4, 6, 7, 9, 11 };
scale_type Lydian(lyd, 7);
//��������� ���
unsigned  int dor[7] = { 0, 2, 3, 5, 7, 9, 10 };
scale_type Dorian(dor, 7);

///////////////////////////////////////////////////////////////////////




//�����: ���
//����������� ��� ������� � ����� ����
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











//�����: ��� �������(��������, ��������)
enum chord_type
{
	M,
	m
};

//�����: ������.
//����������� ����� ������� � ����� ���������
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
//������� ����������� ������ � ������ � ��������� �������
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




//�����: ����
//���� �������� ������������ ���-�� ����������(�� ������������ ���� �����). ������ ���������� ����������� �� 2 �������. ������ �������� � ��������� ���������
//������ ����������� �������� ����� �����(������ ������� ������������� ����� ������� ���� � ������ � ���� ���� ���� �����)
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












//����������� ���� ���������: �������, ������������ ����� ���������, �������� ����� ������������� ������ ����, ��� ��������� ������ ��������������
vector<chord> posibilities(bar chunk, stench reek)
{
	unsigned int L = chunk.length * 2; //����� ����� � ������� �����
	bool fits; //���������� ������ ���������� � ���, �������� �� ��������������� ������ � ������� �����(� ����������� �� ���������� �����������)

	vector<chord> bucket; //����� �������� ������ ��������, ���������� ��� ������������ ���������������� �����



	chord_type type; //��� ��������������� ��������

	scale the_chord_scale; //���, ������� ����� ��������������� ���������������� ������� ��� ��������� ������ ���������������
	//����� ������ �������� � �������, ��� ����� ������� ������ ���������� � ���� ����




	//������� ���������: �������� ���������
	//���������� ��� ���� � ����������� �� ������ ��������������:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Maj; break; }
	case(pentatonic): {the_chord_scale.type = MajPent; break; }
	case(sevenths): {the_chord_scale.type = MajHex; break; }
	case(tritones): {the_chord_scale.type = Lydian; break; }
	}
	type = M;

	//��������� �������� ���������(���������) � �������� ������ �� �������������� ��������������� �� �����:
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




	//������� ���������: �������� ���������
	//���������� ��� ���� � ����������� �� ������ ��������������:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Min; break; }
	case(pentatonic): {the_chord_scale.type = MinPent; break; }
	case(sevenths): {the_chord_scale.type = MinHex; break; }
	case(tritones): {the_chord_scale.type = Dorian; break; }
	}
	type = m;

	//��������� �������� ���������(��������) � �������� ������ �� �������������� ��������������� �� �����:
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




//������� ��������� �� �� ��������, �� ������������� ���� �����, ������� �� ����� ���������� ������� ��������(���� ������� ������������ �������������). ����������������� ����� �� ����� �����������
vector<chord> posibilities(bar chunk, stench reek, unsigned int depth)
{
	unsigned int L = chunk.length * 2; //����� ����� � ������� �����
	bool fits; //���������� ������ ���������� � ���, �������� �� ��������������� ������ � ������� �����(� ����������� �� ���������� �����������)

	vector<chord> bucket; //����� �������� ������ ��������, ���������� ��� ������������ ���������������� �����



	chord_type type; //��� ��������������� ���������

	scale the_chord_scale; //���, ������� ����� ��������������� ���������������� ������� ��� ��������� ������ ���������������
	//����� ������ �������� � �������, ��� �� ����� ������ ���������� � ���� ����




	//������� ���������: �������� ���������
	//���������� ��� ���� � ����������� �� ������ ��������������:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Maj; break; }
	case(pentatonic): {the_chord_scale.type = MajPent; break; }
	case(sevenths): {the_chord_scale.type = MajHex; break; }
	case(tritones): {the_chord_scale.type = Lydian; break; }
	}
	type = M;

	//��������� �������� ���������(���������) � �������� ������ �� �������������� ��������������� �� �����:
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




	//������� ���������: �������� ���������
	//���������� ��� ���� � ����������� �� ������ ��������������:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Min; break; }
	case(pentatonic): {the_chord_scale.type = MinPent; break; }
	case(sevenths): {the_chord_scale.type = MinHex; break; }
	case(tritones): {the_chord_scale.type = Dorian; break; }
	}
	type = m;

	//��������� �������� ���������(���������) � �������� ������ �� �������������� ��������������� �� �����:
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




//������� ��������� �� �� ��������, �� ������������� ���� ����� ����� ���������� ������� ������, ���������� � �������(���������� ����� �������������� � �����)
//��� ���� ��������� ������ ����������������� ������������� �����������(�� ��� � ������ �������������). ������ ����������� ����������(�������� �� ������ ��������� �������) �� ����� �����������
vector<chord> posibilities(bar chunk, stench reek, unsigned int depth, unsigned int pause)
{
	unsigned int L = chunk.length * 2; //����� ����� � �������
	bool fits; //���������� ������ ���������� � ���, �������� �� ��������������� ������ � ������� �����(� ����������� �� ���������� �����������)

	vector<chord> bucket; //����� �������� ������ ��������, ���������� ��� ������������ ���������������� �����



	chord_type type; //��� ��������������� ���������

	scale the_chord_scale; //���, ������� ����� ��������������� ���������������� ������� ��� ��������� ������ ���������������
	//����� ������ �������� � �������, ��� ����� ������ ���������� � ���� ����




	//����� ������������ ������� �������� "������������" ������ ���� �����
	//������ ����� ������������� ����� "0"
	//������ ���� ������������� ���-�� �������, � ������� �-��� ���� ������ ����� �� ��������
	//(�. �. ���������� ����� ������ ���������� ���� ���� � ���� � ������ ���������� ��������� ����)
	//��� �������� ���������� ����������� ��� ����� ����� ��������������� ����, ��� � ���������� ���� ���� 
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
	



	//������� ���������: �������� ���������
	//���������� ��� ���� � ����������� �� ������ ��������������:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Maj; break; }
	case(pentatonic): {the_chord_scale.type = MajPent; break; }
	case(sevenths): {the_chord_scale.type = MajHex; break; }
	case(tritones): {the_chord_scale.type = Lydian; break; }
	}
	type = M;

	//��������� �������� ���������(���������) � �������� ��� �� �������������� ��������������� �� �����:
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




	//������� ���������: �������� ���������
	//���������� ��� ���� � ����������� �� ������ ��������������:
	switch (reek)
	{
	case(chord_tones): {the_chord_scale.type = Min; break; }
	case(pentatonic): {the_chord_scale.type = MinPent; break; }
	case(sevenths): {the_chord_scale.type = MinHex; break; }
	case(tritones): {the_chord_scale.type = Dorian; break; }
	}
	type = m;

	//��������� �������� ���������(���������) � �������� ��� �� �������������� ��������������� �� �����:
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












//��������������� ������� ��� ��������� ����������, ���������� �� ��������������� ������. ������� ����������� ����� ��������� ����� � ����(0, 1, ... , 11) ��� �����(-1)
int option_to_note(int input)
{
	if ((0 <= input) && (input <= 12))
	{
		return (11 - input);
	}
	return -1;
}