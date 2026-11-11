#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans = 0;
void dfs(int x,int cnt,int s){
    if(x>n+1)return;
    if(cnt>=m){
        /*cout<<s<<' '<<ans<<' ';
        cout<<str<<'\n';*/
        ans = max(ans,s);
        return;
    }
    dfs(x+1,cnt+1,s&a[x]);
    dfs(x+1,cnt,s);
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }
    dfs(1,0,INT_MAX);
    cout<<ans;
    return 0;
}
