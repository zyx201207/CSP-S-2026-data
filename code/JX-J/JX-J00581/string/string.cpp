#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define lf double
void op(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
const ll maxn=2e5+10;
ll n;
ll a[maxn],c[maxn];
ll sa[maxn]/**Qian2zhui4he2**/,sb[maxn]/**Hou4zhui4he2**/;
ll ans;
int main(){
    op();
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i){
        scanf("%lld %c",&a[i],&c[i]);
    }
    /*
    for(ll i=1;i<=n;++i){
        printf("%lld %c\n",a[i],c[i]);
    }
    */
    for(ll i=1;i<=n;++i){
        sa[i]=sa[i-1]+a[i];
    }
    for(ll i=n;i>=1;--i){
        sb[i]=sb[i+1]+a[i];
    }/**Ji4suan4 Qian2zhui4he2 and Hou4zhui4he2**/
    ll l=1,r=n;
    ll cl=0,cr=0;/**save last left and right move in $s$"**/
    while(l<=r){
        if(l==r){
            break;//if{l==r}{Yi1ding4 be same}
        }
        if(c[l]!=c[r]){
            ans+=min(sa[l]-cl,sb[r]-cr);
        }
        if(sb[r]==sa[l]){
            cl=sa[l],cr=sb[r];
            ++l;--r;
        }else if(sb[r]<sa[l]){
            cl=cr=sb[r];
            --r;
        }else{
            cl=cr=sa[l];
            ++l;
        }
    }
    printf("%lld",ans);
    return 0;
}
/*
abcdefghijklmnopqrstuvwxyz
1234567890
~!@#$%^&*()-=_+`/,.<>\{}[];':"
operator
*/
