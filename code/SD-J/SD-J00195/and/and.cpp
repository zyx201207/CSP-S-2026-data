#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;
int n,m;
ll ans;
vector <ll> a;
vector <bool> vis;
void dfs(int step,ll num){
    if(step==m){
        ans=max(ans,num);
        return ;
    }
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        vis[i]=true;
        dfs(step+1,num&a[i]);
        vis[i]=false;
    }
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
        vis.push_back(false);
    }
    if(n==m){
        ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        ans=0;
        for(int i=0;i<n;i++){
            ans=max(a[i],ans);
        }
        cout<<ans;
        return 0;
    }
    sort(a.begin(),a.end());
    ans=a[n-1];
    for(int i=n-2;i>=n-m;i--){
        ans=ans&a[i];
    }
    if(ans>=a[n-m]){
        cout<<ans;
        return 0;
    }
    ans=-1;
    for(int i=0;i<n;i++){
        vis[i]=true;
        dfs(1,a[i]);
    }
    cout<<ans;
    return 0;
}
