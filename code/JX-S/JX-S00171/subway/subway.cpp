#include <bits/stdc++.h>
#define il inline
#define rg register
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define int ll
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
namespace XXI{
    //kuaidu kachang!
    //danxiang? shuangxiang?
    const int maxn = 5e5+1000;
    const int maxm = 550;
    int c,n,m,d,q;
    int bel[maxn][25];
    int v[maxn][25];
    int w[maxn];
    int f[maxm][maxm];
    il void read(int & x){
        x = 0;
        char c = getchar();
        bool f = 0;
        while(c<'0' || c>'9'){
            if(c == '-') f = 1;
            c = getchar();
        }
        while(c>='0' && c<='9'){
            x = ((x<<1)+(x<<3))+c-'0';
            c = getchar();
        }
        if(f) x = -x;
    }
    il void write(int x){
        if(x<0){
            putchar('-');
            write(-x);
        } else if(x<10){
            putchar('0'+x);
        } else{
            write(x/10);
            putchar(x%10+'0');
        }
    }
    il void writeln(int x){
        write(x);
        putchar('\n');
    }
    signed main(){
        read(c);
        read(n);
        read(m);
        read(d);
        read(q);
        for(int i = 1;i<=m;i++){
            read(w[i]);
        }
        for(int i = 1;i<=n;i++){
            int k;
            read(k);
            while(k--){
                int a,t;
                read(a);
                read(t);
                bel[a][0]++;
                int x = bel[a][0];
                bel[a][x] = i;
                v[a][x] = t;
            }
        }
        memset(f,0x3f,sizeof(f));
        for(int i = 1;i<=n;i++){
            f[i][i] = 0;
        }
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=bel[i][0];j++){
                for(int k = j+1;k<=bel[i][0];k++){
                    int x = bel[i][j];
                    int y = bel[i][k];
                    f[x][y] = f[y][x] = min(f[x][y],v[i][j]+v[i][k]);
                }
            }
        }
        for(int k = 1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
                }
            }
        }
        while(q--){
            int x,y;
            int ans = LLONG_MAX;
            read(x);
            read(y);
            for(int i = 1;i<=bel[x][0];i++){
                for(int j = 1;j<=bel[y][0];j++){
                    ans = min(ans,v[x][i]+v[y][j]+f[bel[x][i]][bel[y][j]]);
                }
            }
            ans += w[x]+w[y];
            writeln(ans);
        }
        return 0;
    }
}
//Think Twice,Code Once
//Calm Down!
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    XXI::main();
    return 0;
}
