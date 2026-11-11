#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],ans,num[200001];
void dfs(int d,int p,int v){
    //num[d]=a[p];
    if(d==m){
        ans=max(v,ans);
        return;
    }
    for(int i = p+1;i <= n;i++){
        dfs(d+1,i,a[i]&v);
        //cout << d << ' ' << p << ' ' << v << '\n';
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n<=2000){
        dfs(0,0,2147483647);
        cout << ans;
    }
    else cout << 0;
    return 0;
}
