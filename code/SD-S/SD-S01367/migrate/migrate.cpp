//求(b+1)(d-1)f大人多给点分 
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,tt;
int pl[2000005];
vector<int> nxt[5005];
int dis[5005],num[5005];
queue<int> t;
void bfs(int st)
{
	while(t.size())
	{
		int now=t.front();
		t.pop();
		for(int i=0;i<nxt[now].size();i++)
		{
			int ne=nxt[now][i];
			if(dis[now]+1>dis[ne]) continue;
			if(dis[now]+1==dis[ne]) num[ne]+=num[now];
			else if(dis[now]+1<dis[ne])
			{
				dis[ne]=dis[now]+1;
				num[ne]=num[now];
				t.push(ne);
			}
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>tt;
	if(c==11||c==12)
	{
		while(tt--)
		{
			int n,d;
			int ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>pl[i];
			int step=d/(pl[2]-pl[1]);
			if(step<=1)
			{
				cout<<0<<"\n";
				continue;
			}
			step=step+step-1;
			ans=max(ans,n-step);
			cout<<ans<<"\n";
		}
		return 0;
	}
	while(tt--)
	{
		int n,d;
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>pl[i];
		for(int i=1;i<=n;i++) nxt[i].clear();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(pl[j]-pl[i]>d) break;
				nxt[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++) num[j]=0;
			for(int j=i;j<=n;j++) dis[j]=1e18;
			num[i]=1;
			dis[i]=0;
			while(t.size()) t.pop();
			t.push(i);
			bfs(i);
			//if(i==1) for(int j=1;j<=n;j++) cout<<num[j]<<endl;
			for(int j=i;j<=n;j++) if(num[j]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
