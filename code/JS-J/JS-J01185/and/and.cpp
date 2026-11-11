#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=-999;
void dfs(long long sum,long long pos,long long mm){
    if(m-mm-1>n-pos){
        return ;
    }
    if(mm==m){
        ans=max(ans,sum);
        return ;
    }
    dfs(sum,pos+1,mm);
    dfs(sum&a[pos],pos+1,mm+1);
    return ;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}
