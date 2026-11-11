#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,m;
bool vis[MAXN];
int a[MAXN],ans[MAXN];
long long res=-1;
void dfs(int pos){
    if(pos==m+1){
        long long sum=ans[1];
        for(int i=2;i<=m;i++){
            sum&=ans[i];
        }
        res=max(res,sum);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            ans[pos]=a[i];
            vis[i]=true;
            dfs(pos+1);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    dfs(1);
    cout<<res;
}
