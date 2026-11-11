#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005], q[200005];
int tol[200005];
bool vis[200005];

void check(){
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            if(q[i] == q[j] && !vis[i] && !vis[j]){
                for(int k = min(i, j);k <= max(i, j) - 1;k ++){
                    vis[k] = 1;
                }
            }
        }
    }
}

void check2(){
    
}

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n ;i ++){
        memset(vis, 0, sizeof(vis));
        memset(q, 0, sizeof(q));
        for(int j = i;j <= n;j ++){
            q[j] = a[j];
            check();
        }
        for(int i = 1;i <= n;i ++){
            if(!vis[i]) tol[q[i]] ++;
        }
    }
    for(int i = 1;i <= m;i ++){
        cout << tol[i] << " ";
    }
    return 0;
}
