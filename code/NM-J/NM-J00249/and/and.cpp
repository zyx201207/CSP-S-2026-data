#include<bits/stdc++.h>
using namespace std;
int ans = -2147483648;
int a[200005];
bool vis[200005];
int n,m;
void dfs(int pos,int mm,int aand){
    if(pos <= 0 || pos > n){
        return;
    }
    if(mm == 0){
        ans = max(ans,aand);
    }
    if(vis[pos]){
        return;
    }
    for(int i=1;i<=n;i++){
        vis[i] = 1;
        dfs(i,mm-1,aand&a[i]);
        vis[i] = 0;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);


    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1,m,0x7fffffff);

    cout << ans;

    return 0;
}
