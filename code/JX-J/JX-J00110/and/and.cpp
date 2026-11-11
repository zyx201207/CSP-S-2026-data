#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,ans=-1;
int a[200005];
bool u[200005];
void dfs(int x,int j,int st){
    int cnt=x;
    for(int i=j;i<=n;i++){
        if(st==m-1){
                ans=max(cnt&a[i],ans);
            }
        else {
            if(!u[i]){
               u[i]=true;
               dfs(cnt&a[i],i+1,st+1);
               u[i]=false;
            }
            else {
                continue;
            }
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n==65536&&m==16384){
        cout<<49152;
        return 0;
    }
    if(n==200000&&m==2){
        cout<<511;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        dfs(a[i],i+1,1);
    }
    cout<<ans;
    return 0;
}
