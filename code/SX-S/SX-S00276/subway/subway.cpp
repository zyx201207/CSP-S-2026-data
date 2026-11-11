#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+50;
ll c,d,T,n,m,k,ans,sum,num,cnt;
ll vis[N],dis[N],val[N][505];
vector<pair<ll,ll> >vec[N];
void work()
{
	ll rt,ed;
	cin>>rt>>ed;
	memset(vis,0,sizeof vis);
	memset(dis,0x7f,sizeof dis);
	priority_queue<pair<ll,ll> >q;
	q.push({0,rt});
	vis[rt]=1;
	while(!q.empty())
	{
		auto x=q.top();
		ll w=-x.first,u=x.second;
		q.pop();
		vis[u]=1;
		for(auto a:vec[u])
		{
			ll v=a.second;
			if(vis[u]) continue;
			if(dis[u]+w<dis[v])
			{
				q.push({-dis[v],v});
			}
		}
	}
	cout<<dis[ed]<<'\n';
    return;
}
//floyed试制
int main()
{
//    freopen("subway.in","r",stdin);
//    freopen("subway.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    T=1;
    cin>>c>>n>>m>>d>>T;
    for(int i=1;i<=m;++i) cin>>val[i][0];
    for(int i=1;i<=n;++i)
    {
    	cin>>k;
    	ll u,v;
    	for(int j=1;j<=k;++j)
    	{
    		cin>>u>>v;
    		vec[i].push_back({0,u});
    		vec[u].push_back({0,i});
    		val[u][i]=v;
		}
		
	}
	while(T--) work();
    return 0;
}
//差寒挥锋安盛世
//救苦度厄济苍生

//影中故我无暇，落灯花
//孑然立，难逃命煞
//明月映赤霞，大浪淘沙，人生本如画
//何如是，望云涯，四海无家
//昨日希望种下，护城厦
//箭在弦，蓄势待发
//功业仍未罢，一瞬光华，血仇心中扎
//诸般业，尽笑纳，血月正恰