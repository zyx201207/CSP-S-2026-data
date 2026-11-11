#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];
int s[500010];
int k[1010];
int di[1010][1010];
int l[500010],to[500010];
struct node{
    int id,len;
    bool operator <(const node &W)const{
        return len>W.len;
    }
};
struct edge{
    int to,len;
};
vector<edge>mp1[500010];
int dis[1010],vis[1010];
void dij(int s){
    priority_queue<node>q;
    dis[s]=0;
    q.push({s,0});
    while(q.size()){
        int now=q.top().id;
        q.pop();
        if(vis[now]){
            continue;
        }
        vis[now]=1;
        for(auto i:mp1[now]){
            if(dis[i.to]>dis[now]+i.len){
                dis[i.to]=dis[now]+i.len;
                q.push({i.to,dis[i.to]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c>=7&&c<=11){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                di[i][j]=1e9+100;
                if(i==j){
                    di[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            if(k[i]==1){
                int x,y;
                cin>>x>>y;
                continue;
            }else{
                int x,y,s1,s2;
                cin>>x>>s1>>y>>s2;
                di[x][y]=s1+s2;
                di[y][x]=s1+s2;
                mp1[x].push_back({y,s1+s2});
                mp1[y].push_back({x,s1+s2});
            }
        }
        for(int g=1;g<=m;g++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    di[i][j]=min(di[i][j],di[i][g]+di[g][j]);
                }
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<di[l][r]+w[l]+w[r]<<"\n";
        }
        return 0;
    }
    if(c>=1&&c<=6||c==0){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                di[i][j]=1e9+100;
                if(i==j){
                    di[i][j]=0;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>to[j]>>l[j];
            }
            for(int j=1;j<=k[i];j++){
                for(int g=1;g<=k[i];g++){
                    if(j==g){
                        continue;
                    }
                    di[to[j]][to[g]]=l[j]+l[g];
                }
            }
        }
        for(int g=1;g<=m;g++){
            for(int i=1;i<=m;i++){
                for(int j=1;j<=m;j++){
                    di[i][j]=min(di[i][j],di[i][g]+di[g][j]);
                }
            }
        }
        while(q--){
            int l,r;
            cin>>l>>r;
            cout<<di[l][r]+w[l]+w[r]<<"\n";
        }
        return 0;
    }
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;

        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;

    }
    return 0;
}
/*
7 2 3 20 3
2 3 4
2 1 7 3 6
2 3 3 2 2
1 2
2 3
1 3
*/
