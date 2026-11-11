#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	string s, fs;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		int x;
		char a;
		cin >> x >> a;
		while(x--)
		{
			s+=a;
		}
	}
	fs=s;
	long long cnt=0;
	reverse(s.begin(), s.end());
	if(s!=fs)
	{
		int b=s.size();
		for(int i=0; i<s.size(); i++)
		{
			if(s[i]!=s[b])
			{
				fs[i]=fs[b];
				b--;
				cnt++;
			}
		}
	}
	cout << cnt;
}

