#include <iostream>
using namespace std;

struct QJ
{
	long long a;
	char c;
};

long long n, totl, answer;
QJ qjs[200010];

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (long long i =  1; i <=  n; ++i)
	{
		cin >> qjs[i].a >> qjs[i].c;
		totl += qjs[i].a;
	}
	long long leftp = 1, rightp = n;
	bool is_special = false;
	QJ curl = qjs[1], curr = qjs[n];
	while (leftp < rightp)
	{
		if (curl.c != curr.c)
		{
			answer += min(curl.a, curr.a);
		}
		if (curl.a >curr.a)
		{
			int ttt = curl.a - curr.a;
			curl.a = ttt;
			--rightp;
			curr = qjs[rightp];
		}
		else if (curl.a <curr.a)
		{
			int tttt = curr.a - curl.a;
			curr.a = tttt;
			++leftp;
			curl = qjs[leftp];
		}
		else
		{
			++leftp;
			--rightp;
	    	curl = qjs[leftp];
			curr = qjs[rightp];
		}
		
		
		
	}
	cout << answer << endl;
	return 0;
 } 

