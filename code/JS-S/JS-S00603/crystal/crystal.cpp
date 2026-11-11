#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],c[500005],sum,cnt[500005],t,maxn;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for (int i = 2;i <= n;i++){
        sum += (i - 1 - t) * (a[i] - a[i - 1]);
        if (sum > m){
            maxn = max(maxn,i - t - 1);
            for (int j = t + 1;j <= i;j++){
                sum -= a[i] - a[j];
                t++;
                if (sum <= m){
                    break;
                }
            }
        }
        maxn = max(maxn,i - t);
    }
    cout << maxn;
}
