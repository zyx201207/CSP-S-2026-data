#include<bits/stdc++.h>
using namespace std;
const int N = 500001;
int n,m;
long long a[N],f[N][2],ans;
void ne(int x){
    int now = x;
    while (f[x][1]<=m) {
        now--;
        f[x][0]++;
        f[x][1] += a[x]-a[now];
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%lld",&a[i]);
    sort(a + 1,a + n + 1);
    f[1][0] = 1;
    f[1][1] = 0;
    for (int i = 2;i <= n;i++){
        if (f[i-1][1]+f[i-1][0]*(a[i]-a[i-1]) <= m){
            f[i][0] = f[i-1][0]+1;
            f[i][1] = f[i-1][1]+f[i-1][0]*(a[i]-a[i-1]);
        }
        else{
            ne(i);
        }
    }
    for (int i = 1;i <= n;i++) ans = max(ans,f[i][0]);
    cout << ans;
    return 0;
}
