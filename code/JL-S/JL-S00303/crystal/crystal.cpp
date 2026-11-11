#include <bits/stdc++.h>
using namespace std;
int n,l = 1,r = 2;
long long a[500010];
long long c[500010];
unsigned long long m;
long long ans = -1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for (int i = 1;i <= n;i++){
        c[i] = a[i] - a[i-1];
    }
    int cache = c[2];
    while (r <= n){
        while (cache <= m && r <= n){
            r++;
            cache += c[r] * (r - l);
        }
        long long bj = r-l;
        ans = max(ans,bj);
        cache -= (a[r] - a[l]);
        l++;
    }
    cout << ans;
    return 0;
}
