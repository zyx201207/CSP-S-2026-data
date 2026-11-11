#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
const ll maxn=1e6+6;
void op(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
}
ll c,t;
ll n,k;
vector<ll> E[maxn];
ll ans;
bool xz[maxn];
void dfs(ll dq,ll sl){
    if(sl==k){
        return;
    }
    if(sl>k)return;
    if(dq>n)return;
    xz[dq]=1;
    dfs(dq+1,sl+1);
    xz[dq]=0;
    dfs(dq+1,sl);
    return;
}
ll bj[maxn];
ll qaq;
void lol(ll u,ll ste){
    bj[u]=min(bj[u],ste);
    qaq=max(qaq,ste);
    for(ll v:E[u]){
        if(!bj[v]){
            dfs(v,ste+1);
        }
    }
}
int main(){
    op();
    scanf("%lld%lld",&c,&t);
    while(t--){
        qaq=0;
        ans=0;
        scanf("%lld%lld",&n,&k);
        for(ll i=1;i<=n;++i){
            bj[i]=1e18;
            E[i].clear();
        }
        for(ll i=1,u,v;i<n;++i){
            scanf("%lld%lld",&u,&v);
            E[u].push_back(v);
            E[v].push_back(u);
        }
        if(k==1){
            for(ll i=1;i<=n;++i){
                lol(i,0);
            }
            printf("%lld\n",qaq);
        }else if(k==2){
            ll wf=0;
            for(ll i=1;i<=n;++i){
                for(ll j=i+1;j<=n;++j){
                    for(ll af=1;af<=n;++af){
                        bj[af]=1e18;
                    }
                    lol(i,0);lol(j,0);
                    ll twt=0;
                    for(ll af=1;af<=n;++af){
                        twt=max(twt,bj[af]);
                    }
                    wf=max(twt,wf);
                }
            }
            printf("%lld\n",wf);
        }
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()~`_+-={}[]|\:";'<>.
*/
