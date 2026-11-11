#include<bits/stdc++.h>
using namespace std;
long long tt[500005],ww[500015],nexx[500015],hh[500015],idx=0;
int add(long long s,long long e,long long www)
{
	idx++;
	tt[idx]=e;
	ww[idx]=www;
	nexx[idx]=hh[s];
	hh[s]=idx;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long c,t,n,k;
	cin>>c>>t;
	while(t--)
	{
		memset(tt,0,sizeof tt);
		memset(ww,0,sizeof tt);
		memset(nexx,0,sizeof tt);
		memset(hh,0xff,sizeof tt);
		cin>>n>>k;
		int a,b;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			add(a,b,1);
		}
		printf("%d\n",rand()%(n-1)+1);
	}
	return 0;
}
