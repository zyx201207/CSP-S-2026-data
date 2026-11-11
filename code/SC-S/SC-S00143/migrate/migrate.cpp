#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define de(x...) fprintf(stderr,x)
#define rep(i,l,r) for(auto i = l;i <= r;++i)
#define per(i,l,r) for(auto i = l;i >= r;--i)
const int N = 2000005;
int tid,TT,n;
ll m,a[N];
inline ll read(){
    ll x = 0,f = 1;
    char c = getchar();
    while((c ^ 48) > 9){
        if(c == '-')    f = -1;
        c = getchar();
    }
    while((c ^ 48) <= 9)    x = (x<<3) + (x<<1) + (c ^ 48),c = getchar();
    return x * f;
}
int f[N],g[N],s[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    tid = read(),TT = read();
    while(TT--){
        n = read(),m = read();
        rep(i,1,n)  a[i] = read();
        if(n <= 5000){
            int A = 0;
            rep(i,1,n){
                // de("i = %d\n",i);
                rep(j,1,n)    f[j] = n,g[j] = s[j] = 0;
                f[i] = 0,g[i] = s[i] = 1;
                for(int j = i+1,k = i,p = i;j <= n;++j){
                    if(a[j] - a[j-1] > m)   break;
                    while(a[j] - a[k] > m)  ++k;
                    while(p < j && f[p+1] <= f[k])  ++p;
                    f[j] = f[k]+1,g[j] = min(3,s[p] - s[k-1]);
                    // de("  %d | k = %d,p = %d | %d,%d\n",j,k,p,f[j],g[j]);
                    s[j] = s[j-1]+g[j];
                    A += (g[j] == 2);
                }
            }
            printf("%d\n",A);
        }else   printf("0\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}