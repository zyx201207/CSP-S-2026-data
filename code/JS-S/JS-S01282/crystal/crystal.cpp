#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5E5 + 5;
long long a[MAXN];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    cin >> n;
    long long m;
    cin >> m;

    for(int i = 1; i <= n; i++ ) cin >> a[i];
    sort(a + 1, a + 1 + n);

    deque<int> q;
    int ans(1);
    long long cost(0);
    q.push_back(1);

    for(int i = 2; i <= n; i++ ){

        if(q.empty()){
            q.push_back(i);
            cost = 0;
        }else{
            cost += (a[i] - a[i - 1]) * q.size();
            while(cost > m && !q.empty()){
                cost -= a[i] - a[q.front()];
                q.pop_front();
            }
            q.push_back(i);
        }

        ans = max(ans, int(q.size()));

    }

    cout << ans;

    return 0;
}

