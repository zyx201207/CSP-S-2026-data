#include<bits/stdc++.h>
using namespace std;
long long a[300000],ma,ma1,m,n,ans;
void dfs(int x,long long cnt,long long maxn){
    if(cnt==m){
        ma=max(ma,maxn);
        return;
    }
    if(m-cnt+x>n){
        return;
    }
    if(cnt==0){
        maxn=a[x];
    }
    dfs(x+1,cnt+1,maxn&a[x]);
    if(cnt==0){
        maxn=0;
    }
    dfs(x+1,cnt,maxn);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma1=max(mal,a[i]);
    }
    if(m==1){
        cout<<ma1;
    }
    else{
        if(m==n){
            ma1=a[1];
            for(int i=2;i<=n;i++){
                ma1&=a[i];
            }
            cout<<ma1;
        }
        else{
            dfs(1,0,0);
            cout<<ma;
        }
    }
    return 0;
}
