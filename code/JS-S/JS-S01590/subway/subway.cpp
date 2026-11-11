#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int k[500005];
int w[500005];
int a;
int t;
int x,y;
int v[505][505];
int g[500005],b[500005];
int l1,l2;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a>>t;
            v[i][a]=t;
        }
    }
    while(q--){
        cin>>x>>y;
        int ans=INT_MAX;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(v[i][x]!=0&&v[i][y]!=0){
                cout<<w[x]+w[y]+v[i][x]+v[i][y]<<'\n';
                flag=1;
                continue;
            }
            if(v[i][y]!=0){
                g[++l1]=i;
            }
        }
        for(int i=1;i<=n;i++){
            if(v[i][x]!=0){
                b[++l2]=i;
            }
        }
        for(int i=1;i<=l2;i++){
            for(int j=1;j<=l1;j++){
                int h=0;
                for(int k=1;k<=m;k++){
                    if(v[b[i]][k]!=0&&v[g[i]][k]!=0){
                        //cout<<k<<' '<<v[b[i]][k]<<' '<<v[g[i]][k]<<endl;//<<' '<<v[g[j]][x]<<' '<<v[g[j]][k]<<' '<<v[g[i]][k]<<' '<<v[g[i]][y]<<"\n";
                        h+=v[b[j]][x]+v[g[i]][k]+v[b[j]][k]+v[g[i]][y];
                        ans=min(ans,h);
                        h=0;
                    }

                }

            }
        }
        if(flag==0)cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

/*






*/

