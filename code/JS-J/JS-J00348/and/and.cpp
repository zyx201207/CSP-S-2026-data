#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],maxn=INT_MIN,ans;
void dfs(int cnt,int now){
    if(ans<=maxn){
        return;
    }
    if((n-now+1)<(m-cnt)){
        return;
    }
    if(cnt==m){
        maxn=max(maxn,ans);
        return;
    }
    if(now>n){
        return;
    }
    for(int i=1;i<=2;i++){
        if(i==1){
            dfs(cnt,now+1);
        }else if(i==2){
            if(cnt==0){
                ans=a[now];
                dfs(cnt+1,now+1);
                ans=0;
            }else{
                int t=ans;
                ans=ans & a[now];
                dfs(cnt+1,now+1);
                ans=t;
            }
        }
    }
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
    dfs(0,1);
    cout<<maxn<<"\n";
    return 0;
}
