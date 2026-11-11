#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
vector<ll> v, tmp;
ll n, m, p[40], a[N], cnt, ans;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m, p[0] = 1;
    for(int i = 1; i <= 30; i++) p[i] = p[i-1] * 2;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        v.push_back(i);
    }
    for(int i = 30; i >= 0; i--){
        cnt = 0;
        tmp.clear();
        for(auto j : v){
            if((a[j]>>i)&1) cnt++;
        }
        if(cnt < m) continue;
        ans += p[i];
        for(auto j : v)
            if((a[j]>>i)&1) tmp.push_back(j);
        v.clear();
        for(auto j : tmp) v.push_back(j);
        tmp.clear();
        cnt = 0;
    }
    cout << ans << endl;
}
