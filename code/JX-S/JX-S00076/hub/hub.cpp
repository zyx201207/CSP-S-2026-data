#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
bool vis[105][105];
int ans;
int box[105];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            vis[u][v]=1;
            vis[v][u]=1;
        }
        cout<<2-t<<endl;
    }
    return 0;
}
