#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20005],ans;
void dfs(int i,int j,long long sum){
    if(j>=m){
        ans=max(ans,sum);
        return ;
    }
    if(i>n) return ;
    dfs(i+1,j+1,sum&a[i]);
    dfs(i+1,j,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1,0,2147483647);
    cout<<ans;

    return 0;
}
