#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
int n,m;
int a[N];
int ans;
void dfs(int d,int s,int sum){
    if(ans > sum)return;
    if(d == m){
        ans = max(sum,ans);
        return;
    }
    for(int i = s+1;i <= n;i++){
        dfs(d+1,i,sum&a[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int fff = 1;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i] != i-1)fff=0;
    }
    if(n > 2005 && fff){
        ans = a[n];
        for(int i = n;i >=n-m+1;i--)ans &= a[i];
        cout<<ans<<endl;
        return 0;
    }
    for(int i = 1;i <= n-m+1;i++){
        dfs(1,i,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
