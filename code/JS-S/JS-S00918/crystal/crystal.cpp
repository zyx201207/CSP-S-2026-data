#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 500007;
int n,m,a[N],l,sum,cnt = 1,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        sum += cnt * (a[i] - a[i-1]);
        cnt++;
        while(l < i && sum > m) sum -= a[i] - a[l++],cnt--;
        ans = max(ans,cnt);
    }
    cout<<ans<<endl;
}
