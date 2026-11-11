#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M=5e5+5;

ll c,n,m,d,q,f[9005][9005],w[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;

    for(int i=1;i<=n+m;i++){
        for(int j=1;j<=n+m;j++){
            if(i==j) f[i][j]=0;
            else {
                f[i][j]=0x3f3f3f;
                f[j][i]=0x3f3f3f;
            }
        }

    }

    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
        ll k;
        cin>>k;
        for(int j=1;j<=k;j++){
            ll a,t;
            cin>>a>>t;
            f[m+i][a]=t;
            f[a][m+i]=t;
        }
    }



    for(int k=1;k<=n+m;k++){
        for(int i=1;i<=n+m;i++){
            for(int j=1;j<=n+m;j++){
                //cout<<i<<" "<<j<<" "<<k<<"\n";
                //cout<<f[i][j]<<" "<<f[i][k]<<" "<<f[k][j]<<"\n";
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                //cout<<f[i][j]<<"\n";
            }
        }
    }
    //for(int i=1;i<=n+m;i++){
        //for(int j=1;j<=n+m;j++){
            //cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
        //}
    //}


    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<f[x][y]+w[x]+w[y]<<"\n";
    }


    return 0;
}
