#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
const int N = 2e6 + 5;

long long a[N];
long long dis[N];
long long mindis[N];
long long ddd[N];
long long ans;
int vis[N];
void dfs1(int x,long long di){
    if (x > n) return;
    for(int i = x + 1;i <= n;i++){
        if (a[i] > a[x] + d) break;
        if (di > mindis[i]) continue;
        mindis[i] = min(mindis[i],di + 1);
        dfs1(i,di + 1);
    }
}
void dfs2(int x,long long di){
    if (x > n) return;
    for(int i = x + 1;i <= n;i++){
        if (a[i] > a[x] + d) break;
        if (di > mindis[i]) continue;
        if (mindis[i] == di + 1) ddd[i]++;
        dfs2(i,di + 1);
    }
}




int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while(t--){
        ans = 0;
        int cha = 1;
        scanf("%d%ld",&n,&d);
        for(int i = 1;i <= n;i++) scanf("%ld",&a[i]);
        sort(a + 1,a + 1 + n);
        for(int i = 3;i <= n;i++) if (a[i - 1] - a[i - 2] != a[i] - a[i - 1]) cha = 0;
        if (d >= a[n] - a[1]) printf("0\n");
        for(int i = 1;i <= n;i++) {
            memset(ddd,0,sizeof(ddd));
            memset(mindis,0,sizeof(mindis));
            for(int j = 1;j <= n;j++) mindis[j] = LONG_LONG_MAX;
            mindis[i] = 0;
            dfs1(i,0);
            //cout << endl;
            dfs2(i,0);
            for(int j = i + 1;j <= n;j++) if (ddd[j] == 2) ans++;
        }
        printf("%ld\n",ans);

    }



    return 0;
}
