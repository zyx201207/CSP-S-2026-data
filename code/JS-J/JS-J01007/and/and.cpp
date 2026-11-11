#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
long long x,n,m,ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> x;
        a.push_back(x);
    }
    for (long long i = 31;i >= 0;i--){
        vector<long long>cnt;
        for (int j = 0;j < a.size();j++){
            if ((a[j] & (1LL<<i)))
                cnt.push_back(a[j]);
        }
        if (cnt.size() >= m){
            ans += (1LL << i);
            a.swap(cnt);
        }
    }
    cout << ans;
    return 0;
}
