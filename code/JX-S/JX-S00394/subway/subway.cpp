#include<bits/stdc++.h>
using namespace std;
long long c,m,n,d,q;
long long w[500001],k[501],a[500001],t[500001],x[10001],y[10001];
vector <long long> ve[500001];
void edge_add(long long u,long long v){
    ve[u].push_back(v);
}
void f(long long u,long long v){
    queue <long long> q;
    q.push(u);
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j]>>t[j];
            if(j!=1){
                edge_add(a[j-1],a[j]);
            }
        }
    }
 //   for(int i=1;i<=q;i++){
  //      cin>>x[i]>>y[i];
   //     long long ans=0;
   //     ans+=w[x[i]];
   //     ans+=w
   //     f(x[i],y[i]);
   // }
    return 0;
}
