#include<bits/stdc++.h>
using namespace std;
const int inf = 1e6+10;
typedef long long ll;
ll a[inf],n,m;
bool flag = false;
void func(ll x){
    ll valued = 0,ans = 0;
    for(ll i=1;i<x;i++){
        valued += (a[x]-a[i]);
    } if(valued == m){
        ans += x;
        for(ll j=1;j<=n;j++){
            if(a[j] == a[x]){
                ans++;
            } if(a[j] > a[x]){
                break;
            }
        } ans--;
        printf("%lld",ans);
        flag = true;
    } else if(valued > m){
        ans += x;
        for(ll j=1;j<=n;j++){
            if(a[j] > a[x]){
                break;
            }
        } ans--;
        printf("%lld",ans);
        flag = true;
    }
} bool cmp(ll x,ll y){
    return x < y;
} int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    int gongcha;
    bool Aspecial = true,Bspecial = true;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(i == 2){
            gongcha = a[2]-a[1];
        } if(Bspecial && (a[i]-a[i-1] != gongcha)){
            Bspecial = false;
        } if(Aspecial && a[i] != i){
            Aspecial = false;
        }
    } if(Bspecial && !Aspecial){
        ll valueded;
        for(ll i=2;i<=n;i++){
            valueded = (1+(i-1))*(((i-1)-1)/gongcha+1)/2;
            if(valueded == m){
                printf("%lld",i);
                return 0;
            } else if(valueded > m){
                printf("%lld",(i-1));
                return 0;
            }
        }
    } if(Bspecial && Aspecial){
        ll valueded;
        for(ll i=2;i<=n;i++){
            valueded = i*(i-1)/2;
            if(valueded == m){
                printf("%lld",i);
                return 0;
            } else if(valueded > m){
                printf("%lld",(i-1));
                return 0;
            }
        }
    } sort(a+1,a+n+1,cmp);
    for(ll i=2;i<=n;i++){
        func(i);
        if(flag == true){
            break;
        }
    } return 0;
}
