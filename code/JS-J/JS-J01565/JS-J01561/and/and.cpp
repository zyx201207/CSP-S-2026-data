#include <bits/stdc++.h>
using namespace std;
int p[200100],h[200100];
int n,m;
int dfs(int a,int k){
    if(a==0){
        return k;
    }
    int mx=0;
    for(int i = 1;i<=n;i++){
        if(h[i]==0){
            h[i]=1;
            mx=max(mx,dfs(a-1,k&p[i]));
            h[i]=0;
        }
    }
    return mx;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    int o=INT_MAX;
    for(int i = 1;i<=n;i++){
        cin >> p[i];
        o=o&p[i];
    }
    if(m==n){
        cout << o << endl;
        return 0;
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        h[i]=1;
        ans=max(ans,dfs(m-1,p[i]));
        h[i]=0;
    }
    cout << ans;
    return 0;
}
