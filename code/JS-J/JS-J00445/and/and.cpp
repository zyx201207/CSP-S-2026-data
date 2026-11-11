#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005],m,ans=-1,jilu=0;
bool vis[300005];
void dfs(long long x,long long p){
    if(x==m){
        ans=max(ans,p);
    }
    else {
        for(int i=x+1;i<=n;i++){
            if(vis[i]==false){
                vis[i]=true;
                dfs(x+1,p&a[i]);
                vis[i]=false;
            }
        }
    }
}
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        vis[i]=true;
        dfs(1,a[i]);
        vis[i]=false;
    }
    cout<<ans;
    return 0;
}
