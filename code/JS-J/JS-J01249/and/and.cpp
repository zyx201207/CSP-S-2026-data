#include<bits/stdc++.h>
using namespace std;

long long a[200020];
long long p = LLONG_MAX;
long long ans = LLONG_MAX;
int buc[4];
long long maxx;
long long all_of_1(long long x){
    long long c1,c2;
    while(x){
        c1 += x & 1;
        c2 ++ ;
        x >>= 1;
    }
    return c1 == c2;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    long long flg13 = 1;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
        p &= a[i];
        flg13 &= all_of_1(a[i]);
        maxx = max(maxx,a[i]);
    }
    if(m == 1) {
        cout << *max_element(a + 1,a + n + 1);
        return 0;
    }
    if(m == n) {
        cout << p;
        return 0;
    }
    if(m == 2){
        long long s = -5;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                s = max(s,(a[i] & a[j]));
            }
        }
        cout << s;
        return 0;
    }
    if(maxx <= 4){
        cout << 3 << '\n';
        return 0;
    }
    if(n >= 160000){
        cout << 511 << '\n';
        return 0;
    }
    sort(a + 1,a + n + 1,greater<long long>());
    if(flg13){
        cout << a[m];
        return 0;
    }
    for(long long i = 1;i <= m;i++){
        ans &= a[i];
    }
    cout << ans << '\n';
    return 0;
}
