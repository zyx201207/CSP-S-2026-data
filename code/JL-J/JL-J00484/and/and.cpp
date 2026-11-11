#include <bits/stdc++.h>
using namespace std;
int m,n;
long long ans,a[200100],q=1,tn;
void dfs(int cnt,int id,long long sum){
    if(cnt==1)
        sum=a[id];
    if(cnt>1)
        sum=sum&a[id];
    if(sum==0)
        return;
    if(cnt==m){
        if(sum>ans)
            ans=sum;
        return;
    }
    if(cnt>m)
        return;
    for(int i=id+1;i<=n;i++){
        dfs(cnt+1,i,sum);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        tn=a[i];
        dfs(1,i,a[i]);
    }
    cout<<ans;
    return 0;
}
