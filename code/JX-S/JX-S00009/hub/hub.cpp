#include <bits/stdc++.h>
using namespace std;
bool f[10000][10000],a[100000];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            f[u][v]=1;
            f[v][u]=1;
        }
        cout<<1+max((n-1)/2,k)-min((n-1)/2,k)<<endl;
    }
    return 0;
}
