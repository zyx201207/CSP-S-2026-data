#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
void op(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
}
const ll N=2e5+10;
ll baka;
ll n,m;
ll a[N];
bool cmp(ll sum1,ll sum2){
    return sum1>sum2;
}
ll ans;
void dfs(ll x/**Biao3shi4 DQ is Xuan3ze2 where**/,ll y/**Biao3shi4 ZQ Xuan3ze2 how much numbers**/,ll cnt){
    if(y==m){
        ans=max(ans,cnt);
        //printf("%lld\n",cnt);
        return;
    }
    if(x>n)return;
    if(cnt<ans){
        return;//Jian3zhi1
    }
    //1.Xuan3ze2
    //printf("%lld\n",cnt);
    dfs(x+1,y+1,cnt&a[x]);
    //2.not Xuan3ze2
    dfs(x+1,y,cnt);
    return;
}
int main(){
    op();
    //cout<<baka;
    ll hzy=1;
    for(ll i=1;i<=32;++i){
        baka+=hzy;
        hzy*=2;
    }
    //cout<<baka;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    //for(ll i=1;i<=n;++i){
    //    printf("%lld ",a[i]);
    //}
    //cout<<n<<' '<<m;
    if(m==1){
        ll maxa=0;
        for(ll i=1;i<=n;++i){
            maxa=max(maxa,a[i]);
        }
        printf("%lld\n",maxa);
        return 0;
        //Zhi2jie1 find out max{a}
    }else if(m==n){
        ll meow=baka;
        for(ll i=1;i<=n;++i){
            meow&=a[i];
        }
        printf("%lld\n",meow);
        //printf("998244353");
        return 0;
    }else if(m==2&&n<=5008){
        ll ans=0;
        for(ll i=1;i<=n;++i){
            for(ll j=i+1;j<=n;++j){
                ans=max(ans,a[i]&a[j]);
            }
        }
        printf("%lld\n",ans);
        return 0;
    }else if(n<=20){
        dfs(1,0,baka);
        printf("%lld\n",ans);
        return 0;
    }else{
        printf("%lld\n",a[m]);
    }
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
1234567890
~!@#$%^&*()-=_+`/,.<>\{}[];':"
operator
*/
