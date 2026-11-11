#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
void dfs(int p,int i,int s){
    if(p==m){
        ans=max(ans,s);
        return;
    }
    for(int j=i+1;j<=n;j++){
        dfs(p+1,j,s&a[j]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a,a+n+1);
    if(n>2000){
        cout<<a[n-m+1];
        return 0;
    }
    if(n>20){
        if(m=1){
            cout<<a[n];
            return 0;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    dfs(0,1,0x3f);
    cout<<ans;
    return 0;
}
