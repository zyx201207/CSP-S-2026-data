#include<iostream>
#include<vector>
#include<cstdio>
#include<array>
#include<queue>

using namespace std;

int c, t, n, dst, h[5010], d[5010][5010], w[5010][5010], cnt;
array<vector<int>, 5010> edge;
queue<int> q;

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    scanf("%d%d", &c, &t);
    for(int i = 1;i <= t;++t){
        scanf("%d%d", &n, &dst);
        if(n > 5000){
            printf("0\n");
            continue;
        }
        for(int j = 1;j <= n;++j){
            scanf("%d", h+j);
            for(int l = j-1;l && h[j] - h[l] < dst;--l){
                edge[l].push_back(j);
                edge[j].push_back(l);
            }
        }
        for(int j = 1;j <= n;++j){
            q.push(j);
            d[j][j] = 1;
            w[j][j] = 1;
            while(!q.empty()){
                int t = q.front();
                q.pop();
                for(int l : edge[t]){
                    if(d[j][l] == 0){
                        d[j][l] = d[j][t] + 1;
                        w[j][l] = w[j][t];
                        q.push(l);
                    }else if(d[j][l] == d[j][t] + 1){
                        w[j][l] += w[j][t];
                    }
                }
            }
        }
        for(int j = 1;j <= n;++j){
            for(int l = 1;l <= n;++l){
                if(w[j][l] == 2) ++cnt;
                d[j][l] = 0;
                w[j][l] = 0;
            }
            edge[j].clear();
        }
        cnt = 0;
    }
}
