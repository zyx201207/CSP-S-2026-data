#include <bits/stdc++.h>
using namespace std;

string w;

struct node
{
	long long r;
	string s;
}b[200010];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	for(long long i = 1; i <= n; i++)
	{
		cin >> b[i].r >> b[i].s;
		for(long long i = 1; i <= b[i].r; i++)
		{
			w += b[i].s;
		}
	}
	long long cnt = 0, num = w.size() - 1, sum = 0;
	for(long long i = 0; i < w.size(); i++)
	{
		if(w[cnt] != w[num] && cnt != num)
		{
			sum++;
		}
		cnt++;
		num--;
	}
	cout << sum;
	return 0;	
}  
