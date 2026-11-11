#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int c,n,m,d,p,w[N],dis[N][N];
vector<int>l[N];
vector<int>e[N];
int b[N][N],ans=INT_MAX;
int wl[N];
struct node{
    int x,t,l;
};
void bfs(int x,int y,int ll){
    queue<node >q;
    q.push((node){x,w[x]+b[ll][x],ll});
    wl[ll]=1;
    while(!q.empty()){
        node u=q.front();
       // cout<<u.l<<' ';
        q.pop();
        if(b[u.l][y]){
            ans=min(ans,u.t+w[y]+b[u.l][y]);
        }
        int r=u.l;
        for(int i=0;i<l[r].size();i++){
            int qq=l[r][i];
            for(int j=0;j<e[qq].size();j++){
                int v=e[qq][j];
                int cost=b[v][qq ]+b[r][qq ];
                if(!wl[v]||cost+u.t<wl[v ]){
                    node t=(node){qq,cost+u.t,v};
                    wl[v]=cost+u.t;
                    q.push(t);
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int a,y ;
            cin>>a>>y ;
            b[i][a]=y;
            l[i].push_back(a);
            e[a].push_back(i);
        }
    }
    int a,bb;
    for(int i=1;i<=p;i++){
        cin>>a>>bb;
        for(int j=1;j<=m;j++){
            if(b[j][a ])bfs(a,bb,j);
        }
        cout<<ans<<"\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}