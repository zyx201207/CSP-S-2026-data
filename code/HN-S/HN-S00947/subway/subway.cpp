#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,wx[500010];
int e[510][510];
struct ed{
    int x,y;
    ed(int _x = 0,int _y = 0){
        x = _x,y = _y;
    }
};
vector<ed> st[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= n;++j)
            e[i][j] = 1e15 + 7;
    for(int i = 1;i <= m;++i)
        cin>>wx[i];
    for(int i = 1;i <= n;++i){
        int l;
        cin>>l;
        for(int j = 1;j <= l;++j){
            int x,y;
            cin>>x>>y;
            st[x].push_back(ed(i,y));
        }
    }
    for(int i = 1;i <= m;++i)
        for(int x = 0;x < st[i].size();++x)
            for(int y = 0;y < st[i].size();++y){
                if(x == y)continue;
                int u = st[i][x].x,v = st[i][y].x;
                if(e[u][v] > st[i][x].y + st[i][y].y)
                    e[u][v] = st[i][x].y + st[i][y].y;
                if(e[v][u] > st[i][y].y + st[i][x].y)
                    e[v][u] = st[i][y].y + st[i][x].y;
            }
    for(int k = 1;k <= n;++k)
        for(int i = 1;i <= n;++i)
            for(int j = 1;j <= n;++j)
                e[i][j] = min(e[i][j],e[i][k] + e[k][j]);
    for(int i = 1;i <= q;++i){
        int x,y,num = 1e15 + 7;
        cin>>x>>y;
        for(int xx = 0;xx < st[x].size();++xx)
            for(int yy = 0;yy < st[y].size();++yy){
                if(st[x][xx].x == st[y][yy].x){
                    num = min(num,st[x][xx].y + st[y][yy].y);
                    continue;
                }
                num = min(num,e[st[x][xx].x][st[y][yy].x] + st[x][xx].y + st[y][yy].y);
            }
        cout<<num + wx[x] + wx[y]<<'\n';
    }
    return 0;
}