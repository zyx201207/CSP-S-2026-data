#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 5e5 + 5;
const ll MAXX = 1e13 + 5;
int pos[MAX];
int n;
ll m,a[MAX];
bool check(int x){
    memset(pos,0,sizeof(pos));
    ll c = MAXX;
    int tot = 1;
    for(int i = 1;i <= n - x + 1;i++){
        if(a[i + x - 1] - a[i] < c){
            c = a[i + x - 1] - a[i];
            pos[tot] = i;
            tot++;
        }
    }
    ll maxn = a[pos[1]];
    for(int i = pos[1] + 1;i <= pos[1] + x - 1;i++) maxn = max(maxn,a[i]);
    ll ss = 0;
    for(int i = pos[1];i <= pos[1] + x - 1;i++) ss += maxn - a[i];
    ll sss = ss;
    for(int i = 2;i < tot;i++){
        ll maxn = a[pos[i]];
        for(int j = pos[i] + 1;j <= pos[i] + x - 1;j++) maxn = max(maxn,a[j]);
        ll ss = 0;
        for(int j = pos[i];j <= pos[i] + x - 1;j++) ss += maxn - a[j];
        sss = min(sss,ss);
    }
    return (sss <= m);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1);
    int l = 0,r = n;
    int ans = 0;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) ans = mid,l = mid + 1;
        else r = mid - 1;
    }
    cout << ans;

    return 0;
}
