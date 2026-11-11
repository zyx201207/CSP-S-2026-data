#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> a;
long long ans = 0;
long long fi(long long N,long long ans,long long tmp){
    if (N == 0) return ans;
    for(int i = tmp;i < n;i++){
        if (fi)
            tmp = i;
        fi(N-1,ans,tmp);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin >> n >> m;
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        for (int j = i+1;j<n;j++){
            if ((ans[i] & ans[j]) > ans) ans = (ans[i] & ans[j]);
        }
    }
    cout << ans;
    return 0;
}
