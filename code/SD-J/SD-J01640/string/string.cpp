#include<bits/stdc++.h>
using namespace std;
const long long N=2e8;
char a;
char s[N];
long long ans;
int main()
{

	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long t,n=0;
	cin>>t;
	while(t--)
	{
		long long m;
		cin>>m;
		cin>>a;
		for(int i=n;i<n+m;i++)
		{
			s[i]=a;
		}
		n+=m;
	}
	/*
	for(int i=0;i<n;i++)
	{
		cout<<s[i];
	}
	cout<<endl;
	*/
	//cout<<s;
	for(int i=0;i<n/2;i++)
	{
		if(s[i]!=s[n-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

