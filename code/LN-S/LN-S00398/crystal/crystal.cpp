#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[524288];
ll d[524288];
ll s[524288];
ll n, m;
bool cmp(ll a, ll b){
    return a > b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    for(int i=2;i<=n;i++){
        d[i] = a[i] - a[i-1];
        s[i] = s[i-1] + d[i];
    }
    int ans = -114514;
    int res = 1;
    ll cost = 0;
    int sta = 1;

    for(int i=2;i<=n;i++){
        cost += (i-sta)*d[i];
        while(cost > m){
            cost -= s[i];
            cost += s[sta];
            sta ++;
            res --;
            ans = max(ans, res);
        }
        res ++;
        ans = max(ans, res);
    }
    cout<<ans<<endl;
}
