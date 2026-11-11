#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2E5 + 5;
int a[MAXN];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++ ) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());

    set<int> s;
    int i;
    int ans(0);
    for(i = 29; i >= 0; i-- ){

        int cnt(0);
        s.clear();
        for(int j = 1; j <= n; j++ ){
            if((a[j] & (1 << i)) != 0){
                cnt++;
                s.insert(j);
            }
        }

        if(cnt >= m){
            ans = (1 << i);
            break;
        }

    }

    i--;
    for(;i >= 0; i-- ){
        for(int j = 1; j <= n; j++ ){
            if(s.count(j) && ((a[j] & (1 << i)) == 0)){
                s.erase(j);
            }
        }
        if(int(s.size()) < m) break;
        ans += (1 << i);
    }

    cout << ans;

    return 0;
}
