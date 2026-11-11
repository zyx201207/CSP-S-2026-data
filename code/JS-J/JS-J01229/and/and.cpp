#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN = 2005;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n,m,ans = -INF;
ll a[MAXN];
void dfs(ll cnt,ll sum,ll vis){
    if(vis > m) return;
    if(cnt > n){
        if(vis == m){
           ans = max(ans,sum);
        }
        return;
    }
    if(sum == -1){
        sum = a[cnt];
    }
    vis++;
    dfs(cnt + 1,(sum & a[cnt]),vis);
    vis--;
    if(vis == 0){
        dfs(cnt + 1,-1,vis);
    }else{
        dfs(cnt + 1,sum,vis);
    }
    return;
}
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin>>n>>m;
    cin>>a[1];
    ll ma = a[1];
    ll an = a[1];
    for(int i = 2;i <= n;i++){
        cin>>a[i];
        ma = max(ma,a[i]);
        an = an & a[i];
    }
    if(m == 1){
        cout<<ma;
        return 0;
    }
    if(m == n){
        cout<<an;
        return 0;
    }
    if(n <= 20 && m <= n){
        dfs(1,a[1],0);
        cout<<ans;
    }
    return 0;
}
