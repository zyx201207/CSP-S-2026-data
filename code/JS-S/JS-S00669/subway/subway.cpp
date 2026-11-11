#include<bits/stdc++.h>
using namespace std;
const int MAXN=6e5+7;
int c,n,m,d,qq;
int w[MAXN],a[500][MAXN],t[500][MAXN],k[500],x,y;
vector<pair<int,int> >g[MAXN];
int dis[MAXN];
priority_queue<pair<int,int> >Q;
int dij(int s,int e){
    Q.push(make_pair(0,s));
    dis[s]=0;
    while(Q.size()){
        pair<int,int>u=Q.top();
        Q.pop();
        if(u.second==e)break;
        for(auto i:g[u.second])
        {

            if(dis[i.second]!=-1)break;
            Q.push(make_pair(dis[u.second]+i.first,i.second));
            dis[i.second]=dis[u.second]+i.first;
        }
    }
    while(Q.size())Q.pop();
    return dis[e];
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>qq;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        g[i].push_back(make_pair(w[i],i+m));
        g[i+m].push_back(make_pair(w[i],i));
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        cin>>a[i][1]>>t[i][1];
        g[a[i][1]].push_back(make_pair(t[i][1],a[i][1]+m*2));
        g[m*2+1].push_back(make_pair(t[i][1],a[i][1]));
        g[a[i][1]].push_back(make_pair(0,m*2+1));
        g[m*2+1].push_back(make_pair(0,a[i][1]));
        for(int j=2;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            g[a[i][j]].push_back(make_pair(0,a[i][j-1]));
            g[a[i][j-1]].push_back(make_pair(0,a[i][j]));
            g[a[i][j]].push_back(make_pair(t[i][i],a[i][j]+m*2));
            g[m*2+a[i][j]].push_back(make_pair(t[i][i],a[i][j]));
            g[a[i][j]].push_back(make_pair(0,m*2+a[i][j]));
            g[m*2+a[i][j]].push_back(make_pair(0,a[i][j]));
        }
    }
    while(qq--){
        memset(dis,-1,sizeof dis);
        cin>>x>>y;
        cout<<dij(x,y)<<endl;
    }
    return 0;
}

