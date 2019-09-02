#include "Strstring.h"
#include "iostream"

Strstring::Strstring()
{

}
Strstring::~Strstring()
{

}

void Strstring::StringAssign(SeqString *s, char cstr[])
{
	int i =0;
	for(int i=0; cstr[i] != '\0'; i++)
	{
		s->str[i] =  cstr[i];
		s->length =i;
	}

}

bool Strstring::strEmpty(SeqString s)
{
	if(s.length ==0)
	{
	return true;
	}
	else
	{
	return false;
	}
}

int Strstring::StrLength(SeqString s)
{
	return s.length;
}

void Strstring::StrCopy(SeqString *T, SeqString s)
{
	for(int i=0; i<s.length; i++)
	{
		T->str[i] =  s.str[i];
		T->length = s.length;
	}
}

int Strstring::StrCompare(SeqString s, SeqString T)
{
	for(int i=0; i<s.length; i++)
	{
		int dertar = s.str[i] - T.str[i];
		if(dertar > 0)
		{
		return dertar;
		}
		else
		{
		return -dertar;
		}
	}
}

int Strstring::StrInsert(SeqString *T, int pos, SeqString s)
{
	if(pos > MaxLen)
	{
		return -1;
	}
	for(int i =0; i<pos; i++)
	{

	}
}

int Strstring::StrDelete(SeqString *T, int pos, int len)
{
	if(pos <0 || pos > T->length)
	{
		std::cout << "The location is Error!";
		return -1;
	}
	for(int  i = pos -1; i< pos+len; i++)
	{
		T->str[i] = T->str[i+len];
		T->length = T->length - len;
	}
	return 0;
}

int Strstring::StrConcat(SeqString *T, SeqString s)
{
	
	T->str = (char*)realloc(T->str,(T->length + s.length)*sizeof(char));
	if(!T->str)
	{
	std::cout << "realloc Failed";
	return -1;
	}
	else
	{
		for(int i=T->length -1; i < T->length + s.length; i++ )
		{
			T->str[i] = s.str[i-T->length];
			T->length = T->length + s.length;
		}
		return 0;
	}
}

void Strstring::StrClear(SeqString *s)
{
	if(s->str)
	{
		free(s);
	}
	s->str[0] = '\0';
	s->length =0;
	s->length =0;
}