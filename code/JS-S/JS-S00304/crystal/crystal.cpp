#include<bits/stdc++.h>
using namespace std;
int n, ans;
long long m, a[500010];
priority_queue<long long> b[500010];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++){
        long long sum = 0;
        for(int j = i - 1; j >= 1; j--){
            if(sum + a[i] - a[j] <= m){
                sum += (a[j] - a[j]);
                b[i].push(a[i] - a[j]);
            }
            else break;
        }
        sum = 0;
        for(int j = i + 1; j <= n; j++){
            if(sum + a[j] - a[i] <= m){
                sum += (a[j] - a[i]);
                b[i].push(a[j] - a[i]);
            }
            else break;
        }
        int cnt = 0, as = 0;
        while(!b[i].empty()){
            if(cnt + b[i].top() <= m){
                as++;
                cnt += b[i].top();
                b[i].pop();
            }
            else{
                break;
            }
        }
        ans = max(ans, as + 1);
    }
    cout << ans;
    return 0;
}
