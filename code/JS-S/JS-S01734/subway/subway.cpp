#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 505,M = 2e4 + 5;
int n,m,c,d,Q,start,last,ans;
int w[M],k[N],a[N][M],t[N][M];

vector < pair<int,int> > G[N];

struct node{
    int id,line,t;
};

queue <node> q;

void bfs(){
    for(auto Line : G[start])
        q.push({start,Line.first,Line.second});
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        if(tmp.t > ans) continue;
        if(tmp.id == last){
            ans = min(ans,tmp.t);
            continue;
        }
        //change the channel
        for(int i=1;i<=k[tmp.line];i++){
            int point = a[tmp.line][i];
            if(point == last){
                q.push({last,tmp.line,tmp.t + t[tmp.line][i]});
                continue;
            }
            int w = 0;
            for(auto Line : G[point]){
                if(Line.first == tmp.line)
                    w = Line.second;
            }
            for(auto Line : G[point]){
                if(Line.first == tmp.line) continue;
                q.push({point,Line.first,Line.second + w + tmp.t});
            }

        }
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>Q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            G[a[i][j]].push_back({i,t[i][j]});
        }
    }
    while(Q --){
        cin>>start>>last;
        ans = INT_MAX;
        bfs();
        cout<<ans+w[start]+w[last]<<endl;
    }
    return 0;
}
