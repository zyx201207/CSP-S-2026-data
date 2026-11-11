#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+50;
ll c,T,n,m,k,ans,sum,num,cnt;
ll prime[N],vis[N],dis[N][55],cnt1[N];
ll a[N];
vector<ll>vec[N];

ll quick_pow(ll x,ll n)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res*=x;
        x*=x,n>>=1;
    }
    return res;
}
void prime_line(ll n)
{
	memset(vis,0,sizeof vis);
	memset(prime,0,sizeof prime);
	cnt=0;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i]) prime[++cnt]=i;
        for(ll j=1;j<=cnt&&i*prime[j]<=n;++j)
        {
            vis[i*prime[j]]=1;
            if(!i%prime[j]) break;
        }
    }
}
void dj_a(ll rt)
{
	memset(dis,0,sizeof dis);
	memset(cnt1,0,sizeof cnt1);
	queue<pair<ll,ll> >q;
	//node,step;
	q.push({rt,0});
	//vis,step;
	while(!q.empty())
	{
		auto x=q.front();
		ll u=x.first,step=x.second;
		q.pop();
		if(cnt1[u]<50) dis[u][++cnt1[u]]=step;
		for(auto v:vec[u])
		{
			q.push({v,step+1});;
		}
	}
}
void work()
{
	ans=num=sum=cnt=0;
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	memset(cnt1,0,sizeof cnt1);
	for(int i=1;i<=n;++i) vec[i].clear();
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		for(int j=num;j<i;++j)
		{
			if(a[i]-a[j]<=m) vec[j].push_back(i);
			else num++;
		}
	}
//	for(int i=1;i<=n;++i) for(auto v:vec[i]) cout<<i<<" "<<v<<'\n';
	for(int i=1;i<n;++i)
	{
		dj_a(i);
		for(int j=i;j<=n;++j)
		{
			if(dis[j][1]==dis[j][2]&&dis[j][2]!=dis[j][3]) ans++;
		}
	}
	cout<<ans<<'\n';
    return;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    T=1;
    cin>>c>>T;
    if(c==11||c==12)
    {
    	while(T--)
    	{
    		cin>>n>>m;
    		for(int i=1;i<=n;++i)
			{
				cin>>a[i];
			}
			if(a[3]-a[1]>m||m>a[n]-a[1]) cout<<0<<'\n';
			else
			{
				num=m/(a[2]-a[1]);
				cout<<n-num-num+1<<'\n';
			}
		}
    	return 0;
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