#ifndef STRSTRING_H
#define STRSTRING_H

const int MaxLen 100;

typedef struct
{
	char str[MaxLen];
	int length;
}SeqString;

class Strstring
{
public:
	Strstring();
	virtual~Strstring();
public:
	void StringAssign(SeqString *s, char cstr[]);
	//�жϿ�
	bool strEmpty(SeqString s);
	//
	int StrLength(SeqString s);
	// ���ĸ���
	void StrCopy(SeqString *T,SeqString s);
	// �Ƚ��������ĳ���
	int StrCompare(SeqString s, SeqString T);
	//
	int StrInsert(SeqString *T, int pos, SeqString s);
	//
	int StrDelete(SeqString *T, int pos, int s);
	// �������ӵ�����ĩβ
	int StrConcat(SeqString *T, SeqString s);
	//
	void StrClear(SeqString *s);
}

#endif