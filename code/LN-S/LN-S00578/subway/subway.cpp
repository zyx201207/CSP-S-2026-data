#include <bits/stdc++.h>
using namespace std;
long long w[500050];
struct node{
    int from, to, next, len;
}a[1000010];
int pre[500050], k;
void add(int u, int v, int l){
    k++;
    a[k].from = u;
    a[k].to = v;
    a[k].len = l;
    a[k].next = pre[u];
    pre[u] = k;
}
int d[500050];
bool f[500050];
typedef pair<int ,int > P;
priority_queue <P, vector<P>, greater<P> > q;
int c,n,m,d1,p1,x,y;
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d1 >> p1;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    int k, a1, k1, a2, k2;
    for(int i = 1; i <= n;i++){
        cin >> k;
        if(k==1){
            cin >> a1 >> k1;
        }else if(k==2){
            cin >> a1 >> k1 >>a2>>k2;
            add(a1, a2, k1 + k2);
            add(a2, a1, k2 + k1);
        }
    }
    for(int i = 1; i <= p1; i++){
        cin >> x >>y;
        memset(d, 0x3f, sizeof(d));
        memset(f, 0, sizeof(f));
        d[x] = 0;
        q.push({x, 0});
        while(!q.empty()){
            P h = q.top();
            q.pop();
            int p = h.first, dis = h.second;
            if(f[p]) continue;
            for(int i = pre[p]; i; i = a[i].next){
                int to = a[i].to;
                if(dis + a[i].len < d[to]){
                    d[to] = dis + a[i].len;
                    q.push({to, d[to]});
                }
            }
        }
        cout << d[y]+w[x] + w[y] << endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
