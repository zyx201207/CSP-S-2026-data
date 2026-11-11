#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
/*struct tree{
	int l,r,val;
}tr[N*4];
priority_queue<int>pq;
void build(int node,int l,int r)
{
	tr[node].l=l,tr[node].r=r;
	if(l==r) tr[node]=a[l];
	int mid=l+r>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	//
}
*/

inline int read()
{
	int x=0,y=1;
	char ch;
	ch=getchar();
	if(ch=='-') y=-1;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*y;
}
int dp[5005][5005];
int n,d;
map<pair<int,int>,int>mp;
void dfs(int st,int k,int s)
{
	if(dp[st][k]==s){/* cout<<st<<' '<<k<<'\n'; */mp[{st,k}]++;}
	for(int i=k+1;i<=n;i++)
	{
		if(a[i]-a[k]<=d)
		{
			dfs(st,i,s+1);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),T=read();
	while(T--)
	{
		n=read(),d=read();
		if(n<=9)
		{
			mp.clear();
			memset(dp,0,sizeof dp);
			int mn=2e18,mx=-2e18;
			for(int i=1;i<=n;i++){ a[i]=read();mn=min(mn,a[i]);mx=max(mx,a[i]);}
			for(int i=1;i<=n;i++) dp[i][i]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					if(j==i+1) dp[i][j]=1;
					else 
					{
						int x=lower_bound(a+1,a+n+1,a[j]-d)-a;
						x=max(x,i);
						dp[i][j]=min(dp[i][j-1]+1,dp[i][x]+1);
					}
				}
			}
			for(int i=1;i<=n;i++)
			dfs(i,i,0);
			int ans=0;
			for(auto i:mp)
			{
				if(i.second == 2) {/*cout<<i.first.first<<' '<<i.first.second<<'\n';*/ans++;}
			}
			printf("%lld\n",ans);
			continue;
		}
		puts("0");
	}
	return 0;
}

