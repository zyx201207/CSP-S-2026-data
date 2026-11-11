#include<bits/stdc++.h>
using namespace std;
string s,x,y;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,i;
	cin >> n;
	while(n--)
	{
		int a;
		string b;
		cin >> a >> b;
		int i;
		for(i = 1;i <= a;i++)
		{
			s += b; 
		}
	} 
	int len = s.size();
	for(i = 0;i < len / 2;i++)
	{
		x += s[i];
	}
	for(i = len - 1;i > len / 2;i--)
	{
		y += s[i];
	}
	long long cnt = 0;
	for(i = 0;i < x.size();i++)
	{
		if(x[i] != y[i])
		{
			cnt++;
		}
	}
	if(cnt == 0)
	{
		cout << 0 << '\n';
	}
	else
	{
		cout << cnt << '\n';
	}
	return 0;	
} 
