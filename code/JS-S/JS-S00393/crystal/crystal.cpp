#include <bits/stdc++.h>
using namespace std;

int n,ans;long long m,a[500005];
long long sum[500005];

inline long long cover(int x,int y){
    long long hav = sum[y-1]-sum[y-x-1];
    long long need = a[y]*(long long)x;
    return need-hav;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    for(int i = 2;i <= n;i++){
        int lef = 0,rig = i,mid;
        while(lef+1 < rig){
            mid = (lef+rig)/2;
            if(cover(mid,i) <= m){
                lef = mid;
            } else rig = mid;
        }
        ans = max(ans,lef);
    }
    printf("%d",ans+1);
}
