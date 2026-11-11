#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL c,n,m,d,q;
LL w[50005];
LL mp[5105][5105];
LL k,a,t,x,y;
LL MAX=0x3f3f3f3f3f3f3f3f;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(mp,0x3f,sizeof mp);
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];


    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a>>t;
            mp[a][i+ m]=t;
            mp[i+m][a]=t;
        }

    }
    for(int k=1;k<=n+m;k++)
        for(int i=1;i<=n+m;i++)
            for(int j=1;j<=n+m;j++)
                mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);



    for(int i=1;i<=q;i++){
        cin>>x>>y;
        cout<<mp[x][y]+w[x]+w[y]<<'\n';
    }

}

