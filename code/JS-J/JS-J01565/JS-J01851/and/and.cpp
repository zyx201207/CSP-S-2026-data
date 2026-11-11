#include <bits/stdc++.h>
using namespace std;
int a[200005],vis[200005],ans=0,littlemax=-1;
int n,m;
void dfs(int current,int have_number){
    // cout<<have_number<<" "<<current<<endl;
    if(have_number==m){
        ans=max(current,ans);
        // cout<<"specially new ans "<<ans<<endl;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==1){
            continue;
        }
        vis[i]=1;
        dfs(current&a[i],have_number+1);
        vis[i]=0;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        // littlemax=max(littlemax,a[i]);
    }
    dfs(-1,0);
    cout<<ans<<endl;
    return 0;
}