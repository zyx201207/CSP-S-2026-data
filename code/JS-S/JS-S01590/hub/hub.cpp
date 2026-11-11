#include<bits/stdc++.h>
using namespace std;
int c,t;
int re[2000005];
int main(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    int u,v;
    while(t--){
        vector<int>t[`1111111111`];
        int n,k;
        cin>>n>>k;
        int ans=n-1;
        for(int i=1;i<n;i++){
            cin>>u>>v;
            t[u].push_back(v);
            t[v].push_back(v);
        }
        for(int i=1;i<=n;i++){
            re[i]=t[i].size();
        }
        sort(re+1,re+n+1);
        for(int i=n;i>=n-k+1;i--){
            ans-=re[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}/*







*/

