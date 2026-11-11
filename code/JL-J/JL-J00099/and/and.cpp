#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int inf = 2e5+10;
ull a[inf];
bool cmp(ull x,ull y){
    return x > y;
} int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ull n,m;
    scanf("%llu %llu",&n,&m);
    if(m == n){
        ull answers = 1,number;
        for(ull i=1;i<=n;i++){
            scanf("%llu",&number);
            answers &= number;
        } printf("%llu",answers);
        return 0;
    } for(ull i=1;i<=n;i++){
        scanf("%llu",&a[i]);
    } sort(a+1,a+n+1,cmp);
    if(m == 1){
        printf("%llu",a[1]);
        return 0;
    } ull ans = a[1];
    for(ull i=2;i<=m;i++){
        ans &= a[i];
    } printf("%llu",ans);
    return 0;
}
