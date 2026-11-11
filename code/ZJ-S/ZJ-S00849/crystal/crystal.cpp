#include<bits/stdc++.h>
using namespace std;
long long sj,cz;
long long a[500010];
bool xza=1;
bool xzb=1;
long long t,w;
long long h[500010];
long long ans;
bool cmp(long long x,long long y)
{
	return x<y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int jg=0;
	cin>>sj>>cz;
	for(int i=1;i<=sj;i++)
	{
		cin>>a[i];
		if(i==2)
		{
			jg=a[2]-a[1];
		}
		if(i>2)
		{
			if(a[i]-a[i-1]!=jg)xzb=0;
		}
		if(a[i]!=i)xza=0;
	}
	if(xza!=0)
	{
		int i=1;
		while((i*i+i)/2<=cz)i++;
		if(i>sj)i=sj;
		cout<<i;
	}
	else
	{
		if(xzb!=0)
		{
			sort(a+1,a+1+sj,cmp);
			jg=a[2]-a[1];
			int i=1;
			while(jg*(i*i+i)/2<=cz)i++;
			if(i>sj)i=sj;
			cout<<i;
		}
		else
		{
			sort(a+1,a+1+sj,cmp);
			int j=0;
			t=0;
			w=0;
			for(int i=1;i<=sj;i++)
			{
				h[i]=h[i-1]+a[i];
			}
			while((t-w)*a[t]-h[t]+h[w]<=cz && w<=t && t<=sj)
			{
				if((t+1-w)*a[t+1]-h[t+1]+h[w]<=cz)
				{
					t++;
					ans=max(ans,t-w);
				}
				
				else
				{
					w++;
				}
			}
			
			cout<<ans;
		}	
	}
	
	return 0;
}
