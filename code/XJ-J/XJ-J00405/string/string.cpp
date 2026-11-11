#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a;
	int n;
	cin>>n;
	int la = 0;
	while(n--)
	{
		int x;
		char xxx;
		cin>>x>>xxx;
		while(x--)
		{
			la++;
			a = a+xxx;
		}
	}
//	cout<<a<<endl;
//	cout<<la<<endl;
	ll cnt = 0;
	for(int i = 0;i<la/2;i++)
	{
		if(a[i]!=a[la-1-i])
		{
			cnt++;
			a[la+1-i] = a[i];
		}
	}
	cout<<cnt;
	
	return 0;
}
