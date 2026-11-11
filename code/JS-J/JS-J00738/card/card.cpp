#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],lp[300005],ans[500005];
void dfs(int num){
    ans[num]++;
    for(int i=lp[num]+1;i<=n;i++){
        if(lp[a[i]]!=i){
            dfs(a[i]);
            break;
        }
        else ans[a[i]]++;
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        lp[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        dfs(a[i]);
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
