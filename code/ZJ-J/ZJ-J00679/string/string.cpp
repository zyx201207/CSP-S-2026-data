#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
char c[200001];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
	}
	string s="";
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=a[i];++j)
		{
			s=s+c[i];
		}
	}
	int l=s.size();
	int k=0;
	for(int i=0;i<l;++i)
	{
		if(s[i]!=s[l-i-1])++k;
	}
	cout<<k/2;
	return 0;
}