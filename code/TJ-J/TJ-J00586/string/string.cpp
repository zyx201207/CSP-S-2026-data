#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s,x;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		long long m;
		cin>>m;
		cin>>s;
		for(int i=1;i<=m;i++)
		{
			x+=s;
		}
	}
	for(int i=0;i<x.size()/2;i++)
	{
		if(x[i]!=x[x.size()-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
    return 0;
}
