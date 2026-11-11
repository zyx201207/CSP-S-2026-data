#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int x = 0, f = 1;
    char ch = getchar_unlocked();
    while(ch < '0' || ch > '9'){
        if(ch == '-')f = -1;
        ch = getchar_unlocked();
    }
    while(ch >= '0' && ch <= '9'){
        x = (x<<3)+(x<<1)+ch-'0';
        ch = getchar_unlocked();
    }
    return x*f;
}
const int M = 5e5+5;
int c,n,m,d,qq;
int lfy[M];
/*
struct node{
    int v, w;
    bool operator <(const node tk)const{
        return w > tk.w;
    }
};
vector<int> g[M], w[M];
int dis[M],op[M];
priority_queue<node> q;
//queue<int> q;
void dij(int s){
    memset(dis, 0x3f ,sizeof(dis));
    memset(op,0,sizeof(op));
    q.push({s,0});
    dis[s] = 0;
    while(!q.empty()){
        int u = q.top().v;
        q.pop();
        op[u]=1;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i], c = w[u][i];
            dis[u] = min(dis[u], dis[v]+c);
            if(op[v]==0)q.push({v,c});
        }
    }
}*/
int ans[1005][1005];
void floyd(){/*
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < g[i].size; j++){
            ans[i][g[i][j]] = w[i][j];
        }
    }*/
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            for(int k = 1; k <= m; k++){
                ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
            }
        }
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(ans, 0x3f, sizeof(ans));
    c = read(),n=read(),m=read(),d=read(),qq=read();
    for(int i = 1; i <= m; i++)lfy[i] = read();
    for(int i = 1; i <= n; i++){
        int k = read(),id[M]={},t[M]={};
        for(int j = 1; j <= k; j++){
            id[j]=read(),t[j]=read();
            for(int p = 1; p < j; p++){
                ans[id[p]][id[j]]=ans[id[j]][id[p]]=t[j]+t[p];
            }
        }
    }

    floyd();
    while(qq--){
        int x = read(), y = read();
        //dij(x);

        //cout << dis[y]+lfy[x]+lfy[y] << "\n";
        int kskbl = ans[x][y]+lfy[x]+lfy[y];
        printf("%lld\n",kskbl);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
