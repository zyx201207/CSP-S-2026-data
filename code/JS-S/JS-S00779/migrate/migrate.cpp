#include <bits/stdc++.h>
using namespace std;
const int N = 2009051;
typedef long long ll;
// bdrip basic_double_route-ed_island_pair
int c, T, n;
ll pos[N], d, ans;
bool bdrip[N];
inline void testpoint_11_12(){
    ll diff = pos[2]-pos[1];
    if(diff*2>d){
        printf("0\n");
        return;
    }
    int x = (d/diff)*2-1;
    printf("%d\n", max(n-x, 0));
    return;
}
inline void mian(){
    scanf("%d%lld", &n, &d);
    for(int i=1;i<=n;i++){
        scanf("%lld", &pos[i]);
    }
    if(c==11||c==12){
        testpoint_11_12();
        return;
    }
    for(int i=1;i+3<=n;i++){
        int j = i+3;
        bdrip[i] = 0;
        bool flag1 = (pos[j]-pos[i])>d;
        bool flag2 = (pos[j]-pos[j-1])<=d && (pos[j-1]-pos[i])<=d;
        bool flag3 = (pos[j]-pos[i+1])<=d && (pos[i+1]-pos[i])<=d;
        if(flag1&&flag2&&flag3) bdrip[i] = 1;
    }
    ans = 0;
    for(int i=1;i<=3;i++){
        if(!bdrip[i]) continue;
        ll extl = 1, extr = 1;
        int j = i+3;
        for(int k=i-1;k>0;k--){
            if((pos[k+1]-pos[k])<=d&&(pos[k+2]-pos[k])>d) extl++;
            else break;
        }
        for(int k=j+1;k<=n;k++){
            if((pos[k]-pos[k-1])<=d&&(pos[k]-pos[k-2])>d) extr++;
            else break;
        }
        ans += extl*extr;
    }
    printf("%lld\n", ans);
    return ;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &T);
    while(T--) mian();
    return 0;
}