#include <list> 
#include <array>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

list<int> operator*(list<int> a, list<int> b)
{
	if (*--a.end() == 0 || *--b.end() == 0)
	{
		return { 0 };
	}

	list<int> p;
	p.insert(p.begin(), a.size() + b.size() - 1, 0);

	for (pair<int, list<int>::iterator> i(0, a.begin()); i.second != a.end(); ++i.first, ++i.second)
	{
		for (pair<int, list<int>::iterator> j(0, b.begin()); j.second != b.end(); ++j.first, ++j.second)
		{
			list<int>::iterator r;
			advance(r = p.begin(), i.first + j.first);
			*r = (*r) + (*i.second) * (*j.second);
		}
	}
	return p;
}

list<int> operator*(int k, list<int> a)
{
	for (int& e : a) e *= k;
	return a;
}

list<int> xit(list<int> a)
{
	a.push_back(int());
	return a;
}

list<int> operator-(list<int> a)
{
	for (int& e : a) e = -e;
	return a;
}

list<int> operator+(list<int> a, list<int> b)
{
	for (auto it1 = next(next(a.begin())),it2 = b.begin(); it1 != a.end(); it1 = next(it1), it2 = next(it2))
	{
		*it1 += *it2;
	}
	return a;
}


list<int> operator-(list<int> a, list<int> b)
{
	return a + (-b);
}



int main()
{
	vector<list<int>> t(11);
	t[0] = { 1 };
	t[1] = { 1 , 0 };
	for (int i = 2; i < 11; ++i)
	{
		t[i] = 2 * xit(t[i - 1]) - t[i - 2];
	}
	for (int i = 0; i < 11; ++i)
	{
		int cnt = 0;
		cout << "T_" << i << "=";
		for (int e : t[i])
		{
			if (e != 0)
			{
				cout << "(" << e << ")x^" << t[i].size() - cnt - 1;
				if (cnt != t[i].size() - 1) cout << "+";
			}

			cnt++;
		}
		cout << endl;
	}

	return 0;
}