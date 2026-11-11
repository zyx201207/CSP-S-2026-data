#include<bits/stdc++.h>
#define int long long
#define F(a) for(int i=1;i<=a;i++)
#define Fi(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N=510;
const int M=5e5+10;

struct node
{
	int a,t;
	int f[N];
};

int w[N];
int k[N];
vector<int> pass[M];
vector<int> pasn[M];
vector<node> x[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	F(m) cin>>w[i];
	F(n)
	{
		cin>>k[i];
		Fi(j,1,k[i])
		{
			int a,t;
			cin>>a>>t;
			node cnt;
			cnt.a=a,cnt.t=t;
			x[i].push_back(cnt);
			pass[a].push_back(i);
			pasn[a].push_back(j-1);
		}
	}
	while(q--)
	{
		int qd,zd;
		cin>>qd>>zd;
		queue<node> qe;
		node cnt;
		cnt.a=qd,cnt.t=0;
		memset(cnt.f,0,sizeof cnt.f);
		qe.push(cnt);
		int ans=INT_MAX;
		while(qe.size())
		{
			node now=qe.front();
			qe.pop();
			if(now.t>=ans) continue;
			if(now.a==zd)
			{
				ans=min(ans,now.t);
				continue;
			}
			Fi(i,0,pass[now.a].size()-1)
			{
				int ni=pass[now.a][i];
				if(now.f[ni]) continue;
				now.f[ni]=1;
				Fi(j,0,k[ni]-1)
				{
					if(x[ni][j].a==now.a) continue;
					node add;
					add.a=x[ni][j].a,add.t=now.t+x[ni][j].t+x[ni][pasn[now.a][i]].t;
					Fi(boring,1,n) add.f[boring]=now.f[boring];
					qe.push(add);
				}
				now.f[ni]=0;
			}
		}
		cout<<ans+w[qd]+w[zd]<<'\n';
	}
	return 0;
}
