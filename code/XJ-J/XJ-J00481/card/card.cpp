#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
const int M = 3e5 + 5;

int n, m, l[N], vis[N], t[N];
int a[N];
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for(int text = 1; text <= n; text ++){
        memset(vis,0,sizeof(vis));
        for(int i = text; i <= n; i ++){
            if(vis[a[i]] == 0)
                t[a[i]] ++, vis[a[i]] ++;
        }
    }
    for(int i = 1; i <= m; i ++){
        cout << t[i] <<' ';
    }
    return 0;
}