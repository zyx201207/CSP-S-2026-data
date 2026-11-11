#include <bits/stdc++.h>
using namespace std;
int n;
long long m,a[500010],cz,m1,cnt = 1,ans = 0,mx = LONG_MIN;
bool spA,spB;
bool cmp(long long x,long long y){
    return x >= y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        if(a[i] != i){
            spA = false;
        }
    }
    sort(a + 1,a + n + 1,cmp);
    if(spA){
        mx = a[1];
        for(int i = 2;i <= n;i++){
            cz = mx - a[i];
            if(cz <= m){
                m -= cz;
                cnt++;
            }else{
                break;
            }
        }
        printf("%lld",cnt);
        return 0;
    }
    cz = a[1] - a[2];
    for(int i = 2;i <= n;i++){
        if(a[i] - a[i + 1] != cz){
            spB = false;
        }
    }
    if(spB){
        mx = a[1];
        for(int i = 2;i <= n;i++){
            cz = mx - a[i];
            if(cz <= m){
                m -= cz;
                cnt++;
            }else{
                break;
            }
        }
        printf("%lld",cnt);
        return 0;
    }
    for(int i = 1;i <= n;i++){
        m1 = m;
        cnt = 1;
        for(int j = i + 1;j <= n;j++){
            cz = a[i] - a[j];
            if(cz <= m1){
                m1 -= cz;
                cnt++;
            }else{
                break;
            }
        }
        ans = max(ans,cnt);
    }
    printf("%lld",ans);
    return 0;
}
