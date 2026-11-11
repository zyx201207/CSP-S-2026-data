#include<bits/stdc++.h>
using namespace std;
long long n,l,ans;
string m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		char b;
		cin>>a;
		cin>>b;
		for(int j=0;j<a;j++)
		{
			m+=b;
		}
		l+=a;
	}
	for(int i=0;i<l/2;i++)
	{
		if(m[i]!=m[l-i-1])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
