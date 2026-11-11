#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int mnr[2000005];
int mxl[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--)
	{
		int n,d;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			mnr[i]=INT_MAX;
			mxl[i]=INT_MIN;
			if(a[i]-a[i-1]>d)
			{
				mnr[i-1]=i-1;
				mxl[i]=i;
			}
		}
		mnr[n+1]=n;
		for(int i=1;i<=n;i++)mxl[i]=max(mxl[i],mxl[i-1]);
		for(int i=n;i>=1;i--)mnr[i]=min(mnr[i],mnr[i+1]);
		vector<int>g;
		a[n+1]=INT_MAX;
		g.push_back(0);
		for(int i=1;i<=n;i++)
		{
			int nxt=upper_bound(a+i,a+n+2,a[i]+d)-a;
			// printf("11 %d\n",nxt);
			if(nxt==n+1)break;
			if(nxt!=i+3)continue;
			if(a[nxt-1]+d<a[nxt]||a[i]+d<a[nxt-1])continue;
			if(a[nxt-2]+d<a[nxt]||a[i]+d<a[nxt-2])continue;
			g.push_back(i);
		}
		int ans=0;
		// printf("%d\n",(int)g.size());
		for(int i=1;i<(int)g.size();i++)
		{
			if(i==(int)g.size()-1) ans+=(g[i]-max(mxl[i],g[i-1]))*(min(mnr[i],n)-(g[i]+3)+1);
			else ans+=(g[i]-max(mxl[i],g[i-1]))*(min(mnr[i],g[i+1])-g[i]);
		}
		printf("%d\n",ans);
	}
}