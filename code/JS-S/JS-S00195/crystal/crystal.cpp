#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int a[N], n, num, sum, m;
priority_queue<int, vector<int>, greater<int>> pq;
signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ++num;
        sum+=a[i];
        pq.push(a[i]);
        while(num*a[i]>m+sum) {
            sum-=pq.top();pq.pop();--num;
        }
        //cout << num << endl;
        ans=max(ans,num);
    }
    cout << ans << endl;
    return 0;
}
