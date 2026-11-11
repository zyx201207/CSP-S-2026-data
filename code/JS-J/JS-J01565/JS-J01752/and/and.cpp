#include<bits/stdc++.h>
using namespace std;
//#define int long long
int n,m,ans;
int a[200005],g[200005],s[200005];
void dfs(int dep,int sum,int t){
    if(sum < ans) return;
    if(t >= m){
        ans = sum;
        return;
    }if(dep > n) return;
    int x = sum & a[dep];
    if(t == 0){
        x = a[dep];
    }dfs(dep + 1,x,t + 1);
    dfs(dep + 1,sum,t);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }s[1] = a[1];
    for(int i = 2;i <= n;i++){
        s[i] = s[i - 1] & a[i];
    }g[n] = a[n];
    for(int i = n - 1;i >= 1;i--){
        g[i] = g[i + 1] & a[i];
    }if(m == 1){
        int lz = 0;
        for(int i = 1;i <= n;i++){
            lz = max(lz,a[i]);
        }cout << lz;
        return 0;
    }if(m == 2){
        int lz = 0;
        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                lz = max(lz,a[i] & a[j]);
            }
        }cout << lz;
        return 0;
    }if(m == n){
        cout << s[n];
        return 0;
    }if(m == n - 1){
        int lz = 0;
        for(int i = 1;i <= n;i++){
            if(i == 1) lz = max(lz,g[2]);
            else if(i == n) lz = max(lz,s[n - 1]);
            else lz = max(lz,g[i + 1] & s[i - 1]);
        }cout << lz;
        return 0;
    }dfs(1,0,0);
    cout << ans;
    return 0;
}//RP++
