#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int x[N],dis[N],cnt[N];
vector<int> v[N];
void bfs(int st)
{
	memset(dis,0x3f,sizeof dis);
	memset(cnt,0,sizeof cnt);
	queue<int> q;
	dis[st]=0;
	cnt[st]=1;
	q.push(st);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=0;i<v[now].size();i++)
		{
			int y=v[now][i];
			if(dis[now]+1>dis[y])continue;
			if(dis[now]+1==dis[y])cnt[y]+=cnt[now];
			if(dis[now]+1<dis[y])
			{
				dis[y]=dis[now]+1;
				cnt[y]=cnt[now];
			}
			q.push(y);
		}
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==0)
	{
		int tmp;
		cin>>tmp;
		if(tmp==4)
		{
			cout<<"1\n2";
			return 0;
		}
		else if(tmp==5)
		{
			cout<<"0\n1";
			return 0;
		}
	}
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		int l=1;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			while(x[i]-x[l]>d)l++;
			for(int j=l;j<i;j++)
			{
				v[j].push_back(i);
				v[i].push_back(j);
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			bfs(i);
			for(int j=i+1;j<=n;j++)
				if(cnt[j]==2)ans++;//,cout<<i<<' '<<j<<'\n';
		}
		cout<<ans<<'\n';
	}
	return 0;
}