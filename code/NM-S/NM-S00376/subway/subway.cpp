#include <bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=501;
struct Node{
    int to,t;
}to[N][21];
int c,n,m,d,q;
int w[M],k[M];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];//atob
    for(int i=1;i<=n;i++){
        cin>>k[i];//n of pass by
        for(int j=1;j<=k[i];j++){
            cin>>to[i][j].to>>to[i][j].t;
        }
    }
    while(q--){
        int o,f,ans=0;
        cin>>o>>f;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(i==o&&to[i][j].to==o)ans+=to[i][j].t;
                if(to[i][j].to==f)ans+=to[i][j].t;
            }
        }
        ans=ans+w[o]+w[f];
        cout<<ans;
    }
    return 0;
}
