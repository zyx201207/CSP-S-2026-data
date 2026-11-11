#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],sum,cnt,ans;
queue<int> q; //id
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+1+n);
    for(int i = 1;i <= n;i++){
        sum += (a[i]-a[i-1]) * cnt;
        while(sum > m){
            sum -= a[i]-a[q.front()];
            q.pop();
            cnt--;
        }
        q.push(i);
        cnt++;
        ans = max(ans,cnt);
    }
    cout << ans << endl;
    return 0;
}
