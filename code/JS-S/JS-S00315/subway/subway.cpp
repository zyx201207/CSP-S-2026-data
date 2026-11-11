#include<bits/stdc++.h>
using namespace std;
long long w[500001];
vector<int>a[500001];
vector<int>b[500001];
int vi[5001];
int vis[500001];
int to[100][100];
int st[10001],sw[1001];
struct node{
    int id,sum;
};
queue<node>q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C;
    cin>>C;
    if(C>=12&&C<=19){
        int n,m,d,Q;
        cin>>n>>m>>d>>Q;
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }long long tot;
        for(int i=1;i<=n;i++){
            int k,x,y;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>x>>y;tot=y;
                a[i].push_back(x);
                b[x].push_back(i);
            }
        }
        int x,y;long long ans;
        for(int i=1;i<=Q;i++){
            while(!q.empty())q.pop();
            memset(vis,0,sizeof(vis));
            memset(vi,0,sizeof(vi));
            cin>>x>>y;
            q.push({x,0});
            vis[x]=1;
            while(!q.empty()){
                node t=q.front();
                q.pop();
                if(t.id==y){
                    ans=t.sum;
                    break;
                }
                for(int i=0;i<b[t.id].size();i++){
                    if(vi[b[t.id][i]]==1)continue;
                    vi[b[t.id][i]]=1;
                    for(int j=0;j<a[b[t.id][i]].size();j++){
                        int u=a[b[t.id][i]][j];
                        if(vis[u]==0){
                            q.push({u,t.sum+2});
                            vis[u]=1;
                        }
                    }
                }
            }
            cout<<ans*tot+w[x]+w[y]<<"\n";
        }
    }
    else {
        int n,m,d,Q;
        cin>>n>>m>>d>>Q;
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                to[i][j]=0x3f3f3f3f;
                if(i==j)to[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            int k,x,y;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>st[j]>>sw[j];
            }
            for(int j=1;j<=k;j++){
                for(int l=j+1;l<=k;l++){
                    to[st[j]][st[l]]=to[st[l]][st[j]]=min(sw[j]+sw[l],to[st[j]][st[l]]);
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    to[j][k]=min(to[j][k],to[j][i]+to[i][k]);
                }
            }
        }
        int x,y;
        for(int i=1;i<=Q;i++){
            cin>>x>>y;
            cout<<w[x]+w[y]+to[x][y]<<"\n";
        }
    }
    return 0;
}
