#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[200005],v[200005];
void dfs(long long now,long long cnt){
    if(cnt==m){
        ans=max(ans,now);
        return ;
    }
    if(now<=ans)
        return ;

    for(int i=1;i<=n;i++){
        if(v[i]==0){
            v[i]=1;
            dfs((a[i]&now),cnt+1);
            v[i]=0;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++){
        v[i]=1;
        dfs(a[i],1);
        v[i]=0;
    }
    cout<<ans;
    return 0;
}
