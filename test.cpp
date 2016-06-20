#include<iostream>
using namespace std;
//template <typename T>
//T Add(T l, T r)
//{
//	return r + l;
//}
//
//int main()
//{
//	cout << Add(1, 2) << endl;
//	cout << Add(1.2, 2.3) << endl;
//	cout << Add<int>(1, 2.4) << endl;
//	cout << Add(1, 2.4) << endl;
//	cout << Add(1, (int)1.2)<<endl;
//}


//int Max(const int& left, const int & right)
//{
//	return left>right ? left : right;
//}
//template<typename T>
//T Max(const T& left, const T& right)
//{
//	return left>right ? left : right;
//}
//template<typename T>
//T Max(const T& a, const T& b, const T& c)
//{
//	return Max(Max(a, b), c);
//};
//
//template <typename T ,int size=5>
//
//T Sum(int(&arr)[size])
//{
//	assert(arr!=NULL)
//	T sum = arr[1];//此处不能等于0，因为并不能确定T的类型
//	for (int i = 0; i < size; i++)
//	{
//		sum += arr[i];
//	}
//	return sum;
//}



//int main() 
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	Sum(int(&arr)[5]);
//	return 0;
//}
//上述模板并不能用来比较字符串 因此需要进行模板函数特化

template <typename T>
int compare(const T &r, const T &l)
{
	if (r > l)
	{
		return 1;
	}
	else if (r == l)
	{
		return 0;
	}
	else
		return -1;
}
template<>
int compare<const char* &>(const char*&pl, const char* &pr)
{
	return strcmp(pl, pr);
}
int main()
{
	const char* p1 = "123";
	const char* p2 = "456";
	compare(p1, p2);
	compare<>(p1, p2);
	char* p3 = "222";
	char* p4 = "123";
	compare(p3, p4);
}

//模板类
template<typename T>
class Seqlist
{
public:
	Seqlist(size_t capacity = 3)
		_caapcity(capacity)
		, _size(size);
	{
		_pdata = new T[capacity];
	}
	void PushBack(const T&data);
	void Pop()
	{
		assert(_size > 0)
			_size--;
	}
priavte:
	Check capacity()
	{
		if (size >= capacity)
		{
			T*tmp = new T[capacity * 2];
			memcpy(tmp, _pdata, capacity*sizeof(T));
			delete[]_pdata;
			_pdata = tmp;
			capacity *= 2;
		}
	}

private :
	T* _pdata;
	size_t _size;
	size_t _capacity;

};
template<typename T>
void Seqlist<T>::PushBack(const T&data)
{
	_pdata[_size++] = data;
}

class String
{public:
	String(char* str = "")
	{
		if (str == NULL)
		{
			_str = new char[1];
			*_str = '\0';
		}
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
	}
	String(const String &s)
	{
       _str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}
	String & operator=(const String & s)
	{
		if (this != &s)
		{
			char* tmp = new char[strlen(s._str) + 1];
			strcpy(tmp, s._str );
			delete[]_str;
			_str = tmp;
        }
		return *this;
	}
	~String()
	{
		if (_str)
			delete[]_str;
	}

private:
	char* _str;
};
int main()
{
	Seqlist<int>s1;
	Seqlist<char>s2;
	Seqlist<String>s3;
	String s1 = "qwe";
	PushBack(const String &s1);
}
