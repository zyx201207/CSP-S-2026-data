#include <bits/stdc++.h>
using namespace std;
int w[500005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    bool f=0;int T=0;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        bool f1=0;
        int a,t;
        cin>>a>>t;
        int tt=t;
        if(k==m){
            f1=1;
        }
        for(int j=2;j<=k;j++){
            cin>>a>>t;
            if(tt!=t){
                f1=0;
            }
        }
        if(f1==1){
            f=1;
            T=tt;
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        if(f==1){
            cout<<w[x]+w[y]+T+T<<"\n";
        }
        else{
            cout<<w[x]+w[y]+T+T<<"\n";
        }
    }

    return 0;
}
