#include<bits/stdc++.h>
using namespace std;
const int M = 500001;
const int N = 501;
int c,n,m,d,q,wi,k,a,t;
long long dist[2*M+N];
vector<pair<int,int>> son[2*M+N];
long long ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for (int i = 1;i <= m;i++) {
        scanf("%d",&wi);
        son[i].push_back({m+n+i,wi});
        son[m+n+i].push_back({i,wi});
    }
    for (int i = 1;i <= n;i++){
        scanf("%d",&k);
        for (int j = 1;j <= k;j++) {
            scanf("%d%d",&a,&t);
            son[a+n+m].push_back({m+i,t});
            son[m+i].push_back({a+m+n,t});
        }
    }
    for (int i = 1;i <= q;i++){
        int x,y;
        cin >> x >> y;
        memset(dist,0x3f,sizeof(dist));
        queue<pair<int,long long>> q;
        q.push({x,0});
        while (q.size()){
            int u = q.front().first,w = q.front().second;
            for (auto t : son[u])
                if (w + t.second < dist[t.first]){
                    dist[t.first] = w + t.second;
                    q.push({t.first,dist[t.first]});
                }
            q.pop();
        }
        printf("%lld\n",dist[y]);
    }
    return 0;
}
