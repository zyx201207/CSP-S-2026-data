#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s = "";
	cin >> n;
	
	for (int i=1;i<=n;i++)
	{
		long long num;
		char a;
		cin >> num >> a;
		for (int i=1;i<=num;i++)
		{
			s += a;
		}
	}
	int t=0,w=s.size()-1;
	long long cnt = 0;
	while(t<=w)
	{
		if(s[t]!=s[w])cnt++;
		t++;
		w--;
	}
	cout << cnt;
	return 0;
}
