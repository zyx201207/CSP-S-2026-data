#include<bits/stdc++.h>
using namespace std;
int C,T,n;
long long D;
long long x[2000005];
const int INF=1e9;
struct node
{
	long long xi;
	int dp,cnt;
};
int f[5005][5005];
int g[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&C,&T);
	if(C<=6)
	{
		while(T--)
		{
			scanf("%d%lld",&n,&D);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++) f[i][j]=INF,g[i][j]=0;
				f[i][i]=0,g[i][i]=1;
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int mn=INF,cnt=0;
					for(int k=i;k<=j;k++)
						if(x[j]-x[k]<=D)
						{
							if(f[i][k]<mn)
							{
								mn=f[i][k];
								cnt=g[i][k];
							}
							else if(f[i][k]==mn)
							{
								cnt+=g[i][k];
								if(cnt>3) cnt=3;
							}
						}
					if(cnt==2) ans++;
					f[i][j]=mn+1;
					g[i][j]=cnt;
				}
			}
			printf("%d\n",ans);
		}
	}
	else
	{
		while(T--)
		{
			scanf("%d%lld",&n,&D);
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			int ans=0;
			node rst[10];
			deque<node> dq;
			for(int i=1;i<=n;i++)
			{
				dq.push_back((node){x[i],0,1});
				for(int j=i+1;j<=n;j++)
				{
					while(!dq.empty()&&dq.front().xi<x[j]-D) dq.pop_front();
					if(!dq.empty())
					{
						int mn=dq.front().dp,cc=0,cd=0;
						while(!dq.empty()&&dq.front().dp==mn)
						{
							rst[++cc]=dq.front();
							cd+=dq.front().cnt;
							dq.pop_front();
							if(cd>2) break;
						}
						for(int z=cc;z>=1;z--) dq.push_front(rst[z]);
						int fij=mn+1;
						if(cd==2)
						{
							ans++;
						}
						while(!dq.empty()&&dq.back().dp>fij) dq.pop_back();
						dq.push_back({x[j],fij,(cd>3?3:cd)});
					}
				}
				while(!dq.empty()) dq.pop_back();
			}
			printf("%d\n",ans); 
		}
	}
	return 0;
}
