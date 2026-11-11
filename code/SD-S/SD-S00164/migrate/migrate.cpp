#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int c,t;
int n;
long long x[N];
vector <int> g[N];
long long d;
int dp[N];
long long cnt[N];
long long ans;
void bfs(int s)
{
	queue <int> q;
	q.push(s);
	dp[s]=0;
	cnt[s]=1;
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(auto y:g[x])
		{
			if(dp[y]<dp[x]+1) continue;
			cnt[y]+=cnt[x];
			if(dp[y]==dp[x]+1) continue;
			dp[y]=dp[x]+1;
			q.push(y);
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	freopen("migrate2.in","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		ans=0;
		cin>>n>>d;
		if(n>5000)
		{
			long long a,b;
			cin>>a>>b;
			long long z;
			for(int i=3;i<=n;i++) scanf("%lld",&z);
			long long c=b-a;
			long long dt=2*(d/c)-1;
			//cout<<c<<" "<<d<<" "<<d/c<<"\n\n";
			//cout<<n<<" "<<dt<<" ";
			if(c*2ll>d) cout<<0<<"\n";
			else cout<<max(n-dt,1ll*0)<<"\n";
			continue;
		}
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(x[j]-x[i]>d) break;
				g[i].push_back(j);
			}
		}
		for(int i=1;i<=n-2;i++)
		{
			memset(dp,0x3f,sizeof(dp));
			memset(cnt,0,sizeof(cnt));
			bfs(i);
			for(int j=i+1;j<=n;j++) if(cnt[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
