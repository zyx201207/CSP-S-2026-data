#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 5e5 + 5;
ll a[N],m;
int n;
deque<int> q;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >>n >>m;
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    if (n <= 5000){
        int ans = -1;
        for (int i = 1; i <= n; i++){
            int cur = i + 1;
            ll sum = 0;
            while (cur <= n && sum <= m) sum += a[cur++] - a[i];
            ans = max(ans,cur - i - 1);
        }
        cout <<ans;
    }
    else{
        ll sum = 0,ans = 0;
        for (int i = 1; i <= n; i++){
            while (!q.empty() && sum > m){
                sum -= ((a[q.front() + 1] - a[q.front()]) * (q.size() - 1));
                q.pop_front();
            }
            ans = max(ans,ll(q.size()));
            q.push_back(i);
            sum += (a[q.back()] - a[q.front()]);
        }
        cout <<ans;
    }
    return 0;
}
