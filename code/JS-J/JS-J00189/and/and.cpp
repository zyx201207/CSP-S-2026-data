#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m;
int ans;
int dfs(int x,int y,int z){
    if(y==m+1 &&z<=n+1)return x;
    if(z>n+1)return 0;
    ans=max(dfs(x,y,z+1),dfs(x&a[z],y+1,z+1));

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(0x3f3f3f3f,0,1);
    cout<<ans;
    return 0;
}
