#include<bits/stdc++.h>
using namespace std;
long long yu(long long  o,long long  oo){
long long k=o&oo;
return k;
}
long long  n,m,ans=0;
long long a[200001];
void dfs(long long  mq,long long  sy,long long  anss){
    //cout<<mq<<" "<<sy<<" "<<anss<<"\n";
    if(sy==0){
        ans=max(ans,anss);
        return;
    }
    if(n-mq+1<sy) return;
    if(anss<ans&&anss!=-1) return;
    for(long long  i=mq;i<=n-sy+1;i++){
        long long  xans=yu(anss,a[i]);
        if(anss==-1){
            dfs(i+1,sy-1,a[i]);
        }
        else if(xans>ans){
            dfs(i+1,sy-1,xans);
        }
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long  i=1;i<=n;i++)
        cin>>a[i];
    dfs(1,m,-1);
    cout<<ans;
    return 0;
}
