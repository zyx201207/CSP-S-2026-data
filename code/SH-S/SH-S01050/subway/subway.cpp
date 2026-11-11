#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
int w[MAXN],a[MAXN],t[MAXN],startt[MAXN],endd[MAXN],bian[MAXN],timee[MAXN];
int l,o,k,ok,tt,ww;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) 
	{
		cin>>w[i];
	}
	int cnt=0;
	while(cnt<n)
	{
		cin>>k;
		for(int i=cnt*k+1;i<=(cnt+1)*k;i++)
		{
			cin>>a[i]>>t[i];
			if(n==2)
			{
				bian[a[i]]+=cnt+1;
				if(bian[a[i]]==3)
				{
					ok=a[i];
				}
			}
			if(n==3)
			{
				bian[a[i]]+=cnt+1;
				if(bian[a[i]]>=4)
				{
					ok=a[i];
					tt+=t[ok];
					ww+=w[ok];
				}
			}
		}
		cnt++;
	}
	for(int i=0;i<q;i++)
	{
		cin>>startt[i]>>endd[i];
		if(n==1)
		{
			timee[i]=t[startt[i]]+t[endd[i]]+w[startt[i]]+w[endd[i]];
		}
		if(n==2)
		{
			if(bian[startt[i]]==bian[endd[i]]||bian[startt[i]]==3||bian[endd[i]]==3)
		    {
			    timee[i]=t[startt[i]]+t[endd[i]]+w[startt[i]]+w[endd[i]];
		    }
		    else
		    {
		    	timee[i]=t[startt[i]]+t[endd[i]]+w[startt[i]]+w[endd[i]]+t[ok]+w[ok];
			}
		}
		if(n==3)
		{
			timee[i]=t[startt[i]]+t[endd[i]]+w[startt[i]]+w[endd[i]];
		}
		cout<<timee[i]<<endl;
	}
	return 0;
 } 
