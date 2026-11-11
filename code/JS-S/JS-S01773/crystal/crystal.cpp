#include<bits/stdc++.h>
using namespace std;
int n,a[500000];
long long m;
int dfs(int x){
    long long y=m;
    int as=1;
    for(int i=x-1;i>=1;i--){
        if(y<(a[x]-a[i]))break;
        y-=(a[x]-a[i]);
        as++;
    }
    return as;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    stable_sort(a+1,a+1+n);
    int ans=1;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i+1]||i==n)
            ans=max(ans,dfs(i));
    }
    cout<<ans;
    return 0;
}
