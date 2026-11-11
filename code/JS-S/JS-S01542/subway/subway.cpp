#include<iostream>
#include<string.h>
#include<vector>
#include<cstdio>
#include<array>

using namespace std;

struct p{
    int pos, t;
    p(int x, int y){pos = x, t = y;}
    p(){}
};

int c, n, m, d, q, w[500100], k, a, t, x, y;
long long Floyd[510][510], mn;
array<vector<p>, 500100> arr;

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    memset(Floyd, 0x3f, sizeof(Floyd));
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for(int i = 1;i <= m;++i){
        scanf("%d", w+i);
    }
    for(int i = 1;i <= n;++i){
        scanf("%d", &k);
        Floyd[i][i] = 0;
        for(int j = 1;j <= k;++j){
            scanf("%d%d", &a, &t);
            arr[a].push_back({i, t});
        }
    }
    for(int i = 1;i <= m;++i){
        t = arr[i].size();
        for(int j = 0;j < t;++j){
            for(int l = j+1;l < t;++l){
                p tj = arr[i][j], tl = arr[i][l];
                Floyd[tj.pos][tl.pos] = min(Floyd[tj.pos][tl.pos], 0LL + tj.t + tl.t);
                Floyd[tl.pos][tj.pos] = min(Floyd[tl.pos][tj.pos], 0LL + tj.t + tl.t);
            }
        }
    }
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= n;++j){
            for(int l = 1;l <= n;++l){
                Floyd[j][l] = min(Floyd[j][l], Floyd[j][i] + Floyd[i][l]);
            }
        }
    }
    for(int i = 1;i <= q;++i){
        scanf("%d%d", &x, &y);
        a = arr[x].size();
        t = arr[y].size();
        mn = 1LL<<60;
        for(int j = 0;j < a;++j){
            for(int l = 0;l < t;++l){
                p tj = arr[x][j], tl = arr[y][l];
                mn = min(mn, Floyd[tj.pos][tl.pos] + tj.t + tl.t);
            }
        }
        printf("%lld\n", mn + w[x] + w[y]);
    }
}
