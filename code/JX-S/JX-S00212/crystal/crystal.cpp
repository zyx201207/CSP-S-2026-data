#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
typedef pair<ll,ll> pll;
const ll N=5e5+5;
void op(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
ll n,m;
ll a[N];
ll ans;
bool ts;
bool pd_ts(){
    ll mb=a[2]-a[1];
    for(ll i=2;i<=n;++i){
        if(a[i]-a[i-1]!=mb){
            return 0;
        }
    }
    return 1;
}
int main(){
    op();
    ts=1;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1)/**Dui4 Shui1jin1 Jing4xing2 sort**/;

    if(n<=5000){
        for(ll i=1;i<=n;++i){
            ll cnt=1;
            ll cz=0;
            for(ll j=i-1;j>=1;--j){
                if(cz>=m){break;}
                if(cz+a[i]-a[j]<=m){
                    cnt++;
                    cz+=a[i]-a[j];
                }else{
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        printf("%lld\n",ans);
        return 0;
    }

    ts=pd_ts();
    if(ts){
        ll i=n;
        ll cnt=1;
        ll cz=0;
        for(ll j=i-1;j>=1;--j){
            if(cz>=m){break;}
            if(cz+a[i]-a[j]<=m){
                cnt++;
                cz+=a[i]-a[j];
            }else{
                break;
            }
        }
        ans=max(ans,cnt);
        printf("%lld\n",ans);
        return 0;
    }

    if(1){
        vector<pll>tp;/**Yong4 "vector" Dai4ti4 "map" TP**/
        ll lst=0;
        tp.push_back(make_pair(a[1],1));
        for(ll i=2;i<=n;++i){
            if(a[i]!=a[i-1]){
                tp.push_back(make_pair(a[i],1));
                ++lst;
            }else{
                ++tp[lst].second;
            }
        }
        for(ll i=0;i<=lst;++i){
            ll cnt=tp[i].second;
            ll en=m/**Hai2neng2 Jing4xing2 's Cao1zuo4 Ci4shu4**/;
            for(ll j=i-1;j>=0;--j){
                pll dq=tp[j];
                if(en<tp[i].first-dq.first){
                    break;
                }
                if(dq.second*(tp[i].first-dq.first)<=en){
                    cnt+=dq.second;
                    en-=dq.second*(tp[i].first-dq.first);
                }else{
                    cnt+=en/(tp[i].first-dq.first);
                    break;
                }
            }
            ans=max(ans,cnt);
        }
        printf("%lld\n",ans);
        return 0;
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()~`_+-={}[]|\:";'<>.
22:30=>2:30
*/
