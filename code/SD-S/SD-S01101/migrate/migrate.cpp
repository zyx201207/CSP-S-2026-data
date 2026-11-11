#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&(-x))
using namespace std;
int c,t,n,d,x[5005],dis[5005],cnt[5005];
vector<int>vec[5005];
void bfs(int s)
{
	queue<int>q;q.push(s);
	for(int i=1;i<=n;i++) dis[i]=9e18,cnt[i]=0;
	dis[s]=0;
	while(!q.empty())
	{
		int now=q.front();q.pop();
		for(auto it:vec[now])
		{
			int w=dis[now]+1;
			if(w==dis[it]) 
			{
				cnt[it]++;
				q.push(it);
			}
			else if(w<dis[it]) dis[it]=w,cnt[it]=1,q.push(it);
		}
	}
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
		for(int i=1;i<=n;i++) vec[i].clear(); 
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) 
			{
				if(x[j]-x[i]<=d) vec[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
			{
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5

//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
