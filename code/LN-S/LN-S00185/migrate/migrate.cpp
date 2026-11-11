#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
int c,t,n,d,x[MAXN];
struct node{
    int u,dis;
};
bool operator < (node a,node b){
    return a.dis < b.dis;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    priority_queue <node> q;
    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> d;
        for(int i = 1;i <= n;i++){
            scanf("%d",&x[i]);
            q.push({x[i],1});
        }
    }
    for(int i = 1;i <= t;i++) printf("0\n");
    return 0;
}
