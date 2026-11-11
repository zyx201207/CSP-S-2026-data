// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// int Subid,T,n,m,a[2000005],nxt[2000005][21],sum[2000005][21],sum2[2000005][21],tt[2000005],tans[2000005];
// signed main()
// {
// 	scanf("%lld%lld",&Subid,&T);
// 	while(T--)
// 	{
// 		scanf("%lld%lld",&n,&m);int ans=0;
// 		for(int i=1;i<=n;i++) scanf("%lld",a+i);
// 		for(int i=1,p=1,lst=0;i<=n;i++)
// 		{
// 			while(a[i]-a[p]>m) p++;
// 			nxt[i][0]=p;
// 			if(p<i-1&&nxt[p+2][0]>=p) sum2[i][0]=max(0ll,p-nxt[p+1][0]);
// 			else sum2[i][0]=0;
// 			// cerr<<":::::"<<i<<' '<<p<<' '<<nxt[p+1][0]<<' '<<sum2[i][0]<<endl;
// 			// cerr<<"???"<<i<<" "<<nxt[i][0]<<endl;
// 		}
// 		nxt[n+1][0]=-1;
// 		for(int i=n,nw=0;i>=1;i--)
// 		{
// 			if(nxt[i][0]!=nxt[i+1][0]) nw=0;
// 			else nw++;
// 			tt[i]=nw;
// 		}
// 		for(int i=1;i<=n;i++)
// 		{
// 			sum[i][0]=tt[nxt[i][0]];
// 			for(int j=1;j<21;j++) nxt[i][j]=nxt[nxt[i][j-1]][j-1],sum[i][j]=sum[i][j-1]+sum[nxt[i][j-1]][j-1],sum2[i][j]=sum2[i][j-1]+sum2[nxt[i][j-1]][j-1];
// 		}
// 		for(int i=1,lst=0;i<=n;i++)
// 		{
// 			if(nxt[i][0]==i) tans[i]=0;
// 			else if(nxt[i][0]==i-1) tans[i]=tans[i-1];
// 			else
// 			{
// 				cerr<<"????"<<i<<endl;
// 				int p1=i,ans=0;
// 				for(int j=20;j>=0;j--) if(!sum[p1][j]) ans+=sum2[p1][j],p1=nxt[p1][j];
// 				cerr<<"SHU "<<i<<' '<<p1<<endl;
// 				if(nxt[p1][0]==p1||sum[p1][0]>1)
// 				{
// 					tans[i]=0;
// 					// cerr<<"::::"<<i<<' '<<ans<<endl;
// 					continue;
// 				}
// 				cerr<<"QVQV "<<ans<<endl;
// 				int t=p1;p1=nxt[p1][0];
// 				int p2=p1,sum2=0;
// 				for(int j=20;j>=0;j--) if(!sum[p2][j]) p2=nxt[p2][j];
// 				int t1=nxt[i][0]+2,t2=nxt[i][0]+1;
// 				for(int i=20;i>=0;i--) if(nxt[t1][i]!=nxt[t2][i]) t1=nxt[t1][i],t2=nxt[t2][i];
// 				t1=nxt[t1][0];
// 				if(nxt[i][0]==i-2) t1=t2=-1e9;
// 				p2=nxt[p2][0];
// 				if(p1<t1) ans=0;
// 				else p2=max(p2,t2+1),ans=p1-p2;
// 				cerr<<":::::::::::::::::::::"<<t1<<' '<<t2<<' '<<p1<<' '<<p2<<' '<<i<<endl;
// 				tans[i]=ans;
// 				// cerr<<"::::"<<i<<' '<<ans<<' '<<p1<<' '<<p2<<endl;
// 			}
// 			ans+=tans[i];
// 		}
// 		printf("%lld\n",ans);
// 	}
// }
#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5005],dis[5005][5005],cnt[5005][5005];
void bfs(int st)
{
	memset(dis[st],0x3f,sizeof(dis[st]));memset(cnt[st],0,sizeof(cnt[st]));
	dis[st][st]=0;queue<int> q;q.emplace(st);cnt[st][st]=1;
	while(q.size())
	{
		int u=q.front();q.pop();cnt[st][u]=min(cnt[st][u],5ll);
		for(int i=1;i<=n;i++) if(abs(a[u]-a[i])<=m)
		{
			if(dis[st][i]>dis[st][u]+1) dis[st][i]=dis[st][u]+1,q.emplace(i);
			if(dis[st][i]==dis[st][u]+1) cnt[st][i]+=cnt[st][u];
		}
	}
}
int Subid,T;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&Subid,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++) scanf("%lld",a+i);
		for(int i=1;i<=n;i++) bfs(i);int ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<i;j++)
		{
			ans+=(cnt[i][j]==2);
			// if(cnt[i][j]==2) printf("::::::%lld %lld\n",j,i);
		}
		printf("%lld\n",ans);
	}
}