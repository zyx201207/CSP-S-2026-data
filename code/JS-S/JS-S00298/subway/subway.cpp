#include<bits/stdc++.h>
using namespace std;
#define let long long
#define var unsigned long long
const let fic = LLONG_MAX / 2 - 1437;
const int al = 5e5 + 1000;

let w[al];
int c , n , m ,di , qu;

struct node{
    int x;
    let d;
};
vector < node > a[505];
vector < node > v[al];

int k[505];

struct no{
    int x;
    let d;
    bool operator < (const no & b)const{
        return d > b.d;
    }
};

priority_queue< no > q;

let dist[al];

let dijkstra(int st , int ed){
    for(int i = 1;i <= m + n;i ++)
        dist[i] = fic;
    dist[st] = 0;
    q.push({st , 0});
    while(!q.empty()){
        no o = q.top();
        q.pop();
        if(dist[o.x] != o.d)continue;
        //cout << o.x << ' ' << o.d << '\n';
        if(o.x <= m){
            vector < node > &u = v[o.x];
            for(int i = 0;i < u.size();i ++)
                if(dist[u[i].x] > o.d + u[i].d){
                    dist[u[i].x] = o.d + u[i].d;
                    q.push({u[i].x , dist[u[i].x]});
                }
        }else{
            for(int i = 0;i < k[o.x - m];i ++){
               //     cout << 'p' << dist[a[o.x - m][i].x] << ' ' <<  o.d + a[o.x - m][i].d << '\n';
                if(dist[a[o.x - m][i].x] > o.d + a[o.x - m][i].d){
                    dist[a[o.x - m][i].x] = o.d + a[o.x - m][i].d;
                    q.push({a[o.x - m][i].x , dist[a[o.x - m][i].x]});
                }
            }
        }
    }
    return dist[ed];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in" , "r" , stdin);
    freopen("subway.out" , "w" , stdout);

    cin >> c >> n >> m >> di >> qu;
    for(int i = 1;i <= m;i ++)
        cin >> w[i];
    for(int i = 1;i <= n;i ++){
        cin >> k[i];
        for(int j = 1;j <= k[i];j ++){
            int x;let d;
            cin >> x >> d;
            a[i].push_back({x , d});
            v[a[i][j - 1].x].push_back({i + m , a[i][j - 1].d});
        }
    }
    while(qu --){
        int x , y;
        cin >> x >> y;
        cout << dijkstra(x , y) + w[x] + w[y] << '\n';
    }
    return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
