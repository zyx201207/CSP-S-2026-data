#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n,m,maxn = -1,maxx = -1;
    cin >> n >> m;
    vector<long long> a(n+1),pre(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1){
            pre[i] = pre[i - 1] & a[i];
        }else pre[i] = a[i];
        maxn = max(maxn,a[i]);
    }
    if(m == 1) cout << maxn;
    if(m == n) cout << pre[n];
    if(m == 2){
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                maxx = max(maxx,(a[i] & a[j]));
            }
        }
        cout << maxx;
    }
    return 0;
}
