#include<bits/stdc++.h>
using namespace std;
struct node{
    int v , w;
};
vector<node>a[500005];
int ww[1005];
int c[1005][1005];
int main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    int h , n , m , d , q;
    cin >> h >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++){
        int w;
        cin >> w;
        ww[i] = w;
    }
    for(int i = 1 ; i <= n ; i++){
        int k , kk;
        int v , w;
        cin >> k;
        cin >> kk;
        cin >> w;
        a[kk].push_back({kk+i*1000 , w});
        a[kk+i*1000].push_back({kk , w});
        for(int j = 2 ; j <= k ; j++){
            cin >> v >> w;
            a[kk+i*1000].push_back({v+i*1000 , 0});
            a[v+i*1000].push_back({kk+i*1000 , 0});
            a[kk].push_back({kk+i*1000 , w});
            a[kk+i*1000].push_back({kk , w});
            kk = v;
        }
    }
    queue<int> qq;
    for(long long i = 1 ; i <= 1000; i++){
        for(int j = 1; j <= 1000 ; j++){
            c[i][j] = 2e9;
        }
    }
    for(long long i = 1 ; i <= m ; i++){
        c[i][i] = 0;
        qq.push(i);
        while(!qq.empty()){
            int p = qq.front();
            qq.pop();
            for(int k = 0 ; k <= a[p].size() - 1 ; k++){
                //int k = 1;
                int v = a[p][k].v;
                int w = a[p][k].w;
                if(w + c[i][p] < c[i][v]){
                   c[i][v] = w + c[i][p];
                   qq.push(v);
                }
            }
        }
    }
    for(long long i = 1 ; i <= m ; i++){
        for(int j = 1; j <= m ; j++){
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i = 1 ; i <= q ; i++){
        int s , e;
        cin >> s >> e;
        cout << ww[s] + ww[e] + c[s][e] << '\n';
    }
    return 0;
}
