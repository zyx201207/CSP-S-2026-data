#include <bits/stdc++.h>
using namespace std ;
int N;
struct s{
	long long first;
	long long  last;
	char zi;
}st[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	long long lenx=0;
	long long ans=0;
	for(int i=1;i<=N;i++)
	{
		int ch=0;
		char z;
		st[i].first=lenx+1;
		cin>>ch>>z;
		lenx+=ch;
		st[i].last=lenx;
		st[i].zi=z;
	}

	for(long long  j=0, i=1;i<=lenx/2;i++)
	{
		j=lenx-i+1;
		char ic;
		char jc;
		for(int k=1;k<=N;k++)
		{
			if(i<=st[k].last&&i>=st[k].first){
			ic=st[k].zi;break;}
		}
		for(int k=N;k>=1;k--)
		{
			if(j<=st[k].last&&j>=st[k].first){
			jc=st[k].zi;break;}
		}
		if(ic!=jc)
		{
			ans++;
		}
	}
	
	cout<<ans;
}
