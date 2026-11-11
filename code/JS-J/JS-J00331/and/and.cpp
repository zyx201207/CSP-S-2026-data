#include<bits/stdc++.h>
using namespace std;
//whenever where u r,let us enjoy this competition
int n,m;
int arr[200005];
int ans=-1;
bool vis[200005];
void dfs(int x,int tgb){
    if(x==m){
        ans=max(ans,tgb);
        return ;
    }
    if(tgb<=ans){
        return ;
    }
    for(int i=0;i<n;i++){
        int k=tgb;
        if(vis[i])continue;
        if(x==0)k=arr[i];
        k=k&arr[i];
        vis[i]=1;
        dfs(x+1,k);
        vis[i]=0;

    }
    return ;
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(m==n){
        int a=INT_MAX;
        for(int i=0;i<n;i++){
            a=a&arr[i];
        }
        cout<<a;
        return 0;
    }
    dfs(0,INT_MAX);
    cout<<ans<<' ';
    return 0;
}
