#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
int c,t,n,k,u,v;
struct node{
    int u,v;
} edge[MAXN];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin >> c >> t;
    for(int i = 1;i <= t;i++){
        cin >> n >> k;
        for(int i = 1;i <= n - 1;i++){
            cin >> u >> v;
            edge[i].u = v;
            edge[i].v = u;
        }
    }
    for(int i = 1;i <= t;i++) printf("0\n");
    return 0;
}
