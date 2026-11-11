#include<bits/stdc++.h>
using namespace std;
struct node{
    int p,li,ti;
};
int c,n,m,d,q;
int k,s,e,x,y,t;
int w[1005];
vector<int> line[505];
vector<int> lins[505];
vector<int> cha[1005];
bool vis[1005];
void bfs(int s,int e){
    queue<node> q;
    vis[s]=1;
    q.push({s,cha[x][0],w[s]+w[e]+line[cha[x][0]][x]});
    while(!q.empty()){
        node u=q.front();
        int ti=u.ti;
        int p=u.p;
        int li=u.li;
        q.pop();
        if(p==y){
            t=min(t,ti);
            return;
        }
        if(vis[p]){
            return;
        }
        for(auto i : cha[p]){
            for(auto j : lins[i]){
                if(vis[j]){
                    continue;
                }
                else if(i==li){
                    q.push({j,i,ti});
                }
                else{
                    q.push({j,i,ti+line[i][j]+line[li][j]});
                }
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=2*k;j++){
            cin>>x>>y;
            line[i][x]=y;
            lins[i].push_back(x);
            cha[x].push_back(i);
        }
    }
    while(q--){
        cin>>s>>e;
        bfs(s,e);
        cout<<t<<endl;
    }
    return 0;
}
