#include <bits/stdc++.h>
using namespace std;
string n,m,au[10000000000],bu[10000000000];
long long a,b,c,l,w,h,k;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++)//*
	{
		cin>>b>>n;
		w+=b;
		for(int j=l;j<w;j++)
		{
			au[j]=n;
		}
		l+=b;
	}
	h=l/2;
	for(int i=0;i<h;i++)
	{
		if(au[i]!=au[l-1-i])
		{
			c++;
		}
	}
	cout<<c;
	return 0;
}