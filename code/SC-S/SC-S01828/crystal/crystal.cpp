#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b=0,n,m,c[1000001],same=1,r=0,d[1000001],k=0,l=1,o,p;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=2;i<=n;i++)
	{
	  d[i]=c[i]-c[i-1];
	  d[i]=r+(i-1)*d[i];
	  r=d[i];
	}
		for(int i=2;i<=n;i++)
	{
		k=d[i];o=l;
		p=i;
		if(k>m)
		{
		 k=k-d[o]-o*(c[i]-c[o+1]);
		 p=p-o;
		while(k-(c[i]-c[o])>m)
		{
			p=p-1;
		    k=k-(c[i]-c[o]);
			o+=1;
		}p=p-1;l=o;}
		b=max(b,p);
	}
	cout<<b<<endl;
	return 0;
 } 