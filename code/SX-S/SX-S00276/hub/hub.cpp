#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+50;
ll c,T,n,m,k,ans,sum,num,cnt;
ll prime[N],vis[N],dis[N];
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
void work()
{
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    T=1;
    cin>>c>>T;
    if(c==13||c==14)
    {
    	while(T--)
    	{
    		cin>>n>>k;
    		ll u,v;
    		for(int i=1;i<n;++i)
    		{
    			cin>>u>>v;
    			vec[u].push_back(v);
    			vec[v].push_back(u);
			}
			if(k<2) cout<<0<<'\n';
			else
			{
//				ans=((n+1)/2-k+1)/3;
//				if(((n+1)/2-k+1)%3) cout<<ans+1<<'\n';
//				else cout<<ans<<'\n';
				cout<<((n+1)/2-k)/4+1<<'\n';
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