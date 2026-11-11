#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int M = 5e5 + 5;
int w[M],k[505];
int c,n,m,d,q,sum = 0;
struct st{
    int a,t;
    void read(){
        scanf("%d %d",&a,&t);
    }
}p[505][M];
bool cmp(st x,st y){
    if (x.a != y.a) return x.a < y.a;
    return x.t < y.t;
}
ll solve(int s){
    ll ans = 0;
    int l = 1;
    for (int i = 1; i <= n; i++){
        ans += p[l][i].t;
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >>c >>n >>m >>d >>q;
    for (int i = 1; i <= m; i++) scanf("%d",&w[i]),sum += w[i];
    for (int i = 1; i <= n; i++){
        scanf("%d",&k[i]);
        for (int j = 1; j <= k[i]; j++) p[i][j].read();
    }
    for (int i = 1; i <= n; i++) sort(p[i] + 1,p[i] + k[i] + 1,cmp);
    while (q--){
        int s,t;
        cin >>s >>t;
        ll ans = w[s] + w[t];
        ans += solve(s);
        cout <<ans <<"\n";
    }
    return 0;
}
