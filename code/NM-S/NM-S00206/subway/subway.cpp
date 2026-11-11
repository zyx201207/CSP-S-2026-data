#include<bits/stdc++.h>
using namespace std;
struct sta{
    int a,t;
};
struct jih{
    int s,e;
};
int c,n,m,d,q,vis[500005];
sta xian[502][500005];
int w[500002];
vector<int>stat[42];
jih jihu[100001];
void bfs(int s,int e){
    queue<int>q;
    q.push(s);
    vis[1]=s;
    while(!q.empty()){

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
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>xian[i][j].a>>xian[i][j].t;
            stat[xian[i][j].a].push_back()
        }
    }
    for(int i=1;i<=q;i++){
        cin>>jihu[i].s>>jihu[i].e;
    }
    for(int i=1;i<=q;i++){
        bfs(jihu[i].s,jihu[i].e);
    }
}
