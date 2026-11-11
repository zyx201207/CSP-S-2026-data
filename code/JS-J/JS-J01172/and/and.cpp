#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=2e5+10;
int n,m,a[M],ans;
bool f[M];
void dfs(int root,int val,int k){
    if(k==m){
        ans=max(ans,val);
        return;
    }
    f[root]=1;
    for(int i=1;i<=n;i++){
        if(!f[i]) dfs(i,val&a[i],k+1);
    }
    f[root]=0;

}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        dfs(i,a[i],1);
    }
    cout<<ans;
    return 0;
}
