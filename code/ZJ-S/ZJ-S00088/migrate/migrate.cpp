#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5050;
const int MAXN=2e6+15;
int n,d;
int a[MAXN];
int f[N][N],cnt[N][N];
queue<int> q;
void bfs(int s)
{
	for(int i=s+1;i<=n;i++)
	{
		int dis=abs(a[s]-a[i]);
		if(dis>d) break;
		f[s][i]=1;
		q.push(i);
	}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int j=x+1;j<=n;j++)
		{
			int dis=abs(a[x]-a[j]);
			if(dis>d) break;
			if(f[s][j]>f[s][x]+1)
			{
				f[s][j]=f[s][x]+1;
				cnt[s][j]=1;
				q.push(j);
			}
			else if(f[s][j]==f[s][x]+1)
			{
				cnt[s][j]++;
				q.push(j);
			}
		}
	}
}
bool check()
{
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) return 0;
	return 1;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int C,T;
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(d==1)
		{
			cout<<"0\n";
			continue;
		}
		if(check())
		{
			int dif=a[2]-a[1];
			d/=dif;
			int len=d*2-1;
			if(d<=1) cout<<"0\n";
			else cout<<max(n-len,0ll)<<"\n";
			continue;
		}
		memset(f,0x3f,sizeof f);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++) bfs(i);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(cnt[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}