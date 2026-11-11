#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int t,c;
int pre[N],k,res,a[N];
class node
{
public:
	int from,to,len,ne;
	void add(int u,int v,int leng)
	{
		from=u;
		to=v;
		len=leng;
		ne=pre[u];
		pre[u]=k;
	}
}bi[N*N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		res=0,k=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			pre[i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=d)
				{
					bi[++k].add(i,j,1);
				}
			}
		}
//		cout<<1;
		for(int s=1;s<n;s++)
		{
			bool f[n+10];
			int ans[n+10],zui[n+10];
			for(int i=1;i<=n;i++)
			{
				f[i]=1;
				ans[i]=0;
			}
			priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
			q.push({0,s});
			while(!q.empty())
			{
				int fir=q.top().first,sec=q.top().second;
				q.pop();
				if(f[sec])
				{
					zui[sec]=fir;
					ans[sec]++;
				}
				else
				{
					if(zui[sec]==fir)
					{
						ans[sec]++;
					}
					continue;
				}
				f[sec]=0;
				for(int i=pre[sec];i;i=bi[i].ne)
				{
					q.push({fir+1,bi[i].to});
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(ans[j]==2)
				{
					res++;
				}
			}
		}
		cout<<res<<'\n';
	}
	return 0;
}



