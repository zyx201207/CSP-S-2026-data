#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],fa[N];
int dist[1005][1005];
//void check(u,v){
  //  if(dist[u][v]&&u>v) fa[v]=u;
//}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,a,b;
    int n,k,u,v,r;
    bool flag=true;
    cin>>c>>t;
    while(t--){
        flag=true;
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>u>>v;
            dist[u][v]=1;
            dist[v][u]=1;
        }
        //for(int i=1;i<=n;i++){
            //for(int j=i+1;j<=n;j++){
            //    check(u,v);
          //  }
        //}
        cout<<max(1,(n/2)/k);
    }
    return 0;
}
