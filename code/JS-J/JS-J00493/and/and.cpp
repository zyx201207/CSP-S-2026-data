#include<bits/stdc++.h>
using namespace std;

#define int long long

int a[200005];
int n,m,ans;
void dfs(int now,int cnt,int res){
    if(cnt==m){
        ans=max(res,ans);
        return ;
    }
    if(now>n) return ;

    dfs(now+1,cnt+1,res&a[now]);
    dfs(now+1,cnt,res);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];

    int tmp=0;
    for(int i=30;i>=0;i--){
        tmp|=1;
        tmp<<=1;
    }
    tmp|=1;
    dfs(1,0,tmp);

    cout<<ans;

    return 0;
}
