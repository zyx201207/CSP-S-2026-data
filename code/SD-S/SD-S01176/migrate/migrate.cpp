#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define buil(x) __builtin_popcount(x);
#define PII pair<int,int>
#define fi first
#define se second
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
using namespace std;
const int N=2e6+5;
int t,n,m,a[N];
int dp[N],cnt[N],tub[N];
int vis[N];
int c,d;
int query(int u) 
{
	for(int i=1;i<=n;i++) 
	{
		tub[i]=0;
		dp[i]=0;//剩余飞行次数 
		vis[i]=0;//是否符合 
		cnt[i]=1;//最小路径条数
	}
	deque<int>q;
	q.push_back(u);
	vis[u]=0;
	dp[u]=0;
	cnt[u]=1;
	tub[0]=1;
	for(int i=u-1;i>=1;i--)
	{
		
		while(!q.empty() && a[q.front()]-a[i]>d) 
		{
			tub[dp[q.front()]]-=cnt[q.front()];
			q.pop_front();
		}
//		cout<<i<<" "<<q.front()<<"\n";
//cout<<i<<" ";
//for(int j=0;j<=4;j++) cout<<tub[j]<<" ";
//cout<<"\n";
		if(!q.empty())
		{
			dp[i]=dp[q.front()]+1;
			cnt[i]=tub[dp[q.front()]];
			if(cnt[i]==2) vis[i]=1; 
		}
		else break;
		if(!q.empty() && dp[i]<dp[q.back()])
		{
			while(!q.empty() && dp[i]<dp[q.back()])
			{
				tub[dp[q.back()]]-=cnt[q.back()];
				q.pop_back();
			}
		}
		if(dp[i]!=(int)1e9)
		{
			q.push_back(i); 
			tub[dp[i]]+=cnt[i]; 
		}
	}
	int res=0;
	for(int i=1;i<=u;i++) res+=vis[i];
	return res;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    while(t--)
    {
    	cin>>n>>d;
    	for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
    	for(int i=1;i<=n;i++)
    	{
    		ans+=query(i);
		}
		cout<<ans<<"\n";
    	
//query(4);
	}
	return 0;
}

