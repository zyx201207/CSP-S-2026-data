//hun shui mo yu guoqv l
//huaicai zhege daima you dawenti
#include"iostream"
#include"algorithm"
#include"vector"
#include"cmath"
#include"climits"
#define ll long long
ll n,m;
bool special_work(const std::vector<ll> &v){
    ll cha=0;bool cyes=false;
    bool yes=false;
    for(ll i=1;i<=n;i++){
        yes=(bool)(v[i]==i);
        ll c=v[i]-v[i-1];
        if(i==1){
            cha=c;
            continue;
        }
        cyes=(bool)(cha==c);
    }
    if(yes){
        m*=2;ll ans=0;
        ll p=std::floor(std::sqrt(m));
        if(p*(p+1)<=m){
            ans=p+1;
        }else{
            ans=p;
        }
        std::cout<<ans;
    }else if(cyes){
        ll ans=0; m*=2; m/=cha;
        ll p=std::floor(std::sqrt(m));
        if(p*(p+1)<=m){
            ans=p+1;
        }else{
            ans=p;
        }
        std::cout<<ans;
    }
    return (yes||(cha!=0));
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin>>n>>m;//balls*n,did*m
    std::vector<ll> v(n+5,0);
    ll cnt=0;
    for(ll i=1;i<=n;i++){
        ll x; std::cin>>x;
        v[i]=x;
        cnt+=std::abs(x);
    }
    std::sort(v.begin()+1,v.begin()+1+n);
    if(cnt>=1e12){
        bool b=special_work(v);
        if(b){//special_work effect
            return 0;
        }
    }
    ll l=1,r=n,ans=-1;
    for(ll op=1;op<=n;op++){
        ll total=m;//can be used
        ll cntans=0;
        ll mid=v[op];//target to be
        for(ll i=1;i<=n;i++){
            ll p=mid-v[i];
            if(p>=0){
                if(total>=p){
                    total-=p;
                    cntans++;
                }
            }else{
                break;
            }
        }
        ans=std::max(ans,cntans);
    }
    std::cout<<ans;
    return 0;
}
