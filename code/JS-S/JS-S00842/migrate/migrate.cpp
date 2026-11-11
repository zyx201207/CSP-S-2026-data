#include<bits/stdc++.h>
//International Grandmaster zheng_iii bless me
//International Grandmaster cdx123456 bless me
//Grandmaster Cubber bless me
using std::pair;
using std::make_pair;
typedef long long ll;
typedef long double ld;
const int maxn=1e9+7;
const ll N=2000010;
ll test_c,T,n,d,a[N],pre[N],suf[N];
ll c[11][11],b[11][11];
void solve1(){
    memset(b,0x3f,sizeof(b));
    memset(c,0,sizeof(c));
    for(int msk=0;msk<(1<<n);msk++){
        for(int i=1;i<=n;i++){
            if(msk>>(i-1)&1){
                for(int j=i+1;j<=n;j++){
                    if(msk>>(j-1)&1){
                        std::vector<ll> vec;
                        ll sum=-1;
                        for(int k=1;k<=n;k++){
                            if(msk>>(k-1)&1){
                                vec.push_back(k);
                                sum++;
                            }
                        }
                        if(vec[0]!=i)continue;
                        if(vec.back()!=j)continue;
                        bool ok=1;
                        for(int k=1;k<(int)vec.size();k++){
                            if(a[vec[k]]-a[vec[k-1]]>d){
                                ok=0;
                            }
                        }
                        if(!ok)continue;
                        if(sum<b[i][j]){
                            b[i][j]=sum;
                            c[i][j]=1;
                        }else if(sum==b[i][j]){
                            c[i][j]++;
                        }
                    }
                }
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(c[i][j]==2){
                ans++;
            }
        }
    }
    std::cout<<ans<<"\n";
}
void solve2(){
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(i<suf[i]-1&&suf[suf[i]-1]>suf[i]&&pre[suf[suf[i]-1]]==suf[i]-1){
            ans++;
        }
    }
    std::cout<<ans<<"\n";
}
void SOLVE(){
    std::cin>>n>>d;
    for(int i=1;i<=n;i++){
        std::cin>>a[i];
    }
    ll pl=1;
    for(int i=1;i<=n;i++){
        while(a[i]-a[pl]>d)pl++;
        pre[i]=pl;
    }
    pl=n;
    for(int i=(int)n;i>=1;i--){
        while(a[pl]-a[i]>d)pl--;
        suf[i]=pl;
    }
    if(test_c<=2)solve1();
    else if(test_c==11||test_c==12)solve2();
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin>>test_c>>T;while(T--)SOLVE();
    return 0;
}
