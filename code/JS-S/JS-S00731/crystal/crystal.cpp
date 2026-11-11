#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500009];
__int128_t f[500009];
void print(__int128_t x){
    if(x) print(x/10);
    else return;
    putchar(x%10+'0');
}
int n,m;
int check(int x,int y){
    return ((__int128_t)a[y]*(y-x) - f[y-1] + f[x-1]) <= m;
}
signed main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld %lld",&n,&m);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    int ans = 0;
    for(int i = 1;i<=n;i++) f[i] = a[i] + f[i-1];
    for(int i = 1;i<=n;i++){
        int l = 1, r = i;
        while(l<r){
            int mid = l + (r-l)/2;
            if(check(mid,i)){
                r = mid;
            }else{
                l = mid+1;
            }
        }
        if(check(l,i)) ans = max(ans,i-l+1);
    }
    printf("%lld\n",ans);
}
