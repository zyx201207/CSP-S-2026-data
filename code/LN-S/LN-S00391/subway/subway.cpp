#include <bits/stdc++.h>
using namespace std;
const int N = 550,M = 5e5 + 10,INF = 0x3f3f3f3f;
struct node{
    int to,next;
}a[M];
struct edge{
    int dx,t;
}b[10][M];
int c,n,m,x,y,d,q,l[M];
int l1[M],l2[M],w[M];
int k = 0,pre[N];
int dd[N];
void add(int u,int v){
    a[++k] = {v,pre[u]};
    pre[u] = k;
}
queue<int> qq;
bool f[N];
long long ans = 0;
void spfa(){
    memset(dd,0,sizeof(dd));
    dd[x] = 0;
    qq.push(x);
    ans = w[x];
    f[x] = true;
    while(!qq.empty()){
        int h = qq.front();
        qq.pop();
        f[h] = false;
        for(int i = pre[h];i;i = a[i].next){
            int to = a[i].to;
            if(dd[h] + w[i] < dd[to]){
                dd[to] = dd[h] + w[i];
                if(!f[to]){
                    qq.push(to);
                    f[to] = true;
                }
            }
        }
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> m >> n >> d >> q;
    for(int i = 1;i <= n;i++){
        cin >> w[i];
    }
    for(int i = 1;i <= m;i++){
        cin >> l[i];
        for(int j = 1;j <= l[i];j++){
            cin >> b[i][j].dx >> b[i][j].t;
        }
    }
    for(int i = 1;i <= m;i++){
        cin >> l[i];
        for(int j = 1;j <= l[i];j+= 2){
            add(b[i][j].dx,b[i][j + 2].dx);
            add(b[i][j + 2].dx,b[i][j].dx);
        }
    }
    for(int i = 1;i <= q;i++){
        cin >> x >> y;
        if(n <= 2){
            if(x != y && d == 1){
                cout << b[1][x].t + b[1][y].t + w[1] + w[2] <<'\n';
                continue;
            }else if(x == y){
                cout << 0;
                continue;
            }else if(x != y && d > 2){
                int ans = INT_MAX;
                for(int i = 1;i <= m;i++){
                  //  for(int j = 1;j <= l[i];j++){
                        ans = min(ans,b[i][x].t + b[i][y].t);
                   // }
                }
                cout << ans + w[x] + w[y] <<'\n';
                continue;
            }
        }
        if(d == 1){
            spfa();
            cout << dd[y] <<'\n';
        }
    }
    return 0;
}
