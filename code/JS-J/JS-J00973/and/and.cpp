#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n,m,ans,maxn,maxa;
int a[N];
bool pa;
void dfs(int dep,int k,int res){
    if(dep > n){
        if(k == m)ans = max(ans,res);
        return;
    }
    if(k == 0){
        dfs(dep + 1,1,a[dep]);
        dfs(dep + 1,0,res);
    }
    else{
        dfs(dep + 1,k + 1,res & a[dep]);
        dfs(dep + 1,k,res);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    maxa = a[1];
    for(int i = 1;i <= n;i ++ ){
        cin >> a[i];
        maxn = max(maxn,a[i]);
        maxa = maxa & a[i];
    }
    if(n <= 20){
        dfs(1,0,0);
        cout << ans << endl;
        return 0;
    }
    else if(m == 1){
        cout << maxn << endl;
        return 0;
    }else if(m == 2){
         for(int i = 1;i <= n;i ++ ){
            for(int j = 1;j <= n;j ++ ){
                if(i == j)continue;
                ans = max(ans,(a[i] & a[j]));
            }
         }
         cout << ans << endl;
         return 0;
    }else if(m == n - 1){
        for(int i = 1;i <= n;i ++ ){
            int k = maxa ^ a[i];
            ans = max(ans,k);
        }
        cout << ans << endl;
        return 0;
    }else{
        sort(a + 1,a + n + 1);
        ans = a[n];
        for(int i = n;i >= n - m + 1;i -- ){
            ans = ans & a[i];
        }
        cout << ans << endl;
    }
   return 0;
}
