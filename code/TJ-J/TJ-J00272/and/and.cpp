#include<bits/stdc++.h>
using namespace std;
int xo[1000];
int yo[1000];
int aans[1000];
int fand(int x,int y)
{
	
	int ms=1;
	while(x)
	{
		xo[ms]=x%2;
		x/=2;
		ms++;
	}
	int msy=1;
	while(y)
	{
		yo[msy]=y%2;
		y/=2;
		msy++;
	}
	for(int l=1,r=ms-1;l<=r;l++,r--)
	{
		swap(xo[l],xo[r]);
	}
	int az=abs(ms-msy);
	if(ms>msy)
	{
		for(int i=msy-1;i>0;i--)
		{
			yo[i+az]=yo[i];
			yo[i]=0;
		}
		msy=ms;
	}
	else if(ms<msy)
	{
		for(int i=ms-1;i>0;i--)
		{
			xo[i+az]=xo[i];
			xo[i]=0;
		}
		ms=msy;
	}

	for(int i=ms-1;i>0;i--)
	{
		int baas=0;
		if(xo[i]&&yo[i])
		{
			baas=1;
		}
		aans[ms-i-1]=baas;
	}
	int tnt=0;
	for(int i=0;i<ms-1;i++)
	{
		tnt+=aans[i]*pow(2,i);
	}
	return tnt;
}
int a[1100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxp=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<n;i++)
	{
		maxp=max(maxp,fand(a[i],a[i+1]));
	}
	cout<<maxp;
	return 0;
}
