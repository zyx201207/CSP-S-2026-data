#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans;
int n,m;
void dfs(long long x,int dep,int z){
    if(dep==0){
        ans=max(x,ans);
        return;
    }
    for(int i=z+1;i<=n;++i){
        long long nx=a[i];
        a[i]=0;
        if(x==-1){
            dfs(nx,dep-1,i);
        }else{
            dfs(x&nx,dep-1,i);
        }
        a[i]=nx;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
///////////// I want to 1/2*AC.
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    dfs(-1,m,0);
    cout<<ans<<"\n";
    return 0;
}
