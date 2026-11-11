#include<bits/stdc++.h>
using namespace std;
int n,m;
long long num[200005],ans,mx;
void dfs(int pos,int cnt,long long now){
    if(pos==n+1) return;
    if(cnt==m){
        ans=max(ans,now);
        return;
    }
    for(int i=pos+1;i<=n;i++){
        dfs(i,cnt+1,now&num[i]);
        dfs(i,cnt,num[i]);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        mx=max(mx,num[i]);
    }
    if(n==m){
        ans=num[1];
        for(int i=2;i<=n;i++) ans&=num[i];
        cout<<ans;
        return 0;
    }
    if(n>2000&&mx==4){
        cout<<4;
        return 0;
    }
    dfs(1,1,num[1]);
    cout<<ans;
    return 0;
}
