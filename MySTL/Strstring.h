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
	//判断空
	bool strEmpty(SeqString s);
	//
	int StrLength(SeqString s);
	// 串的复制
	void StrCopy(SeqString *T,SeqString s);
	// 比较两个串的长度
	int StrCompare(SeqString s, SeqString T);
	//
	int StrInsert(SeqString *T, int pos, SeqString s);
	//
	int StrDelete(SeqString *T, int pos, int s);
	// 将串连接到串的末尾
	int StrConcat(SeqString *T, SeqString s);
	//
	void StrClear(SeqString *s);
}

#endif