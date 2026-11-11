#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,m,a[MAXN],ans;
void dfs(int k,int num,int s){
    if(num>m)return;
    if(k==n+1){
        if(num==m){
            ans=max(ans,s);
        }
        return;
    }
    dfs(k+1,num,s);
    if(num==0)dfs(k+1,num+1,a[k]);
    else dfs(k+1,num+1,s&a[k]);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans<<"\n";
    return 0;
}