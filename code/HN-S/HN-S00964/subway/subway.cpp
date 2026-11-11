#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e2+10,N=5e5+10,inf=1e18;
int C,n,m,d,q,w[N],f[M][M];
struct node{
    int id,z;
};
vector<node>v[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>C>>m>>n>>d>>q;
    for(int i=1;i<=n;i++)   
        cin>>w[i];
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int pt,t;
            cin>>pt>>t;
            v[pt].push_back(node{i,t});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++)
            f[i][j]=inf;
        f[i][i]=0;    
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            for(int k=j+1;k<v[i].size();k++){
                int x=v[i][j].id,y=v[i][k].id,val=v[i][j].z+v[i][k].z;
                f[x][y]=min(f[x][y],val);
                f[y][x]=min(f[y][x],val);
            }
        }
    }
    for(int k=1;k<=m;k++)
        for(int i=1;i<=m;i++)
            for(int j=1;j<=m;j++)
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y,ans=inf;
        cin>>x>>y;
        for(int i=0;i<v[x].size();i++){
            for(int j=0;j<v[y].size();j++){
                int px=v[x][i].id,py=v[y][j].id,val=v[x][i].z+v[y][j].z;
                ans=min(ans,val+f[px][py]);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}   