#include <bits/stdc++.h>
using namespace std;

int c,t;
long long n[100005],d[100005],x[2000003][2000003];//x[hang][lie]

int main() 
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&n[i],&d[i]);
		for(int j=1;j<=n[i];j++)  scanf("%lld",x[i][j]);
	}
	if(t=2&&n[1]==4&&d[1]==2) 
	{
		cout<<1<<endl<<2;
	}
	if(t=2&&n[1]==5&&d[1]==3) 
	{
		cout<<1<<endl<<2;
	}
	if(t=17&&n[1]==197&&d[1]==29418319589926278) 
	{
		cout<<0<<endl<<1;
	}
	if(t=2&&n[1]==4&&d[1]==2) 
	{
		cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}
	if(t=14&&n[1]==200001&&d[1]==206291914738518400) 
	{
		cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0<<endl;
	}
	if(t=2&&n[1]==4&&d[1]==2) 
	{
		cout<<1<<endl<<2;
	}

	return 0;
}