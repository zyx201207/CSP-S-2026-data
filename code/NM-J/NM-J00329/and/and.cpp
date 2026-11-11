// 09:44 5/5 100pts
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define endl '\n'
int n, m;
struct qw
{
    int raw, num[40];
}a[200010];
int cnt[40];
bool cmp(qw x, qw y){
    for(int i = 35; i; i--){
        if(cnt[i] < m)
            continue;
        if(x.num[i] != y.num[i])
            return x.num[i] > y.num[i];
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int tmp;
        cin >> tmp;
        a[i].raw = tmp;
        vector<int> t;
        while(tmp){
            t.push_back(tmp % 2);
            tmp /= 2;
        }
        for(int j = 0; j < t.size(); j++){
            a[i].num[j+1] = t[j];
        }
    }

    for(int i = 35; i; i--){
        int tmp = 0;
        for(int j = 1; j <= n; j++)
            tmp += a[j].num[i];
        cnt[i] = tmp;
    }

    sort(a+1, a+n+1, cmp);

    int ans = a[1].raw;
    for(int i = 1; i <= m; i++)
        ans &= a[i].raw;
    cout << ans;
}