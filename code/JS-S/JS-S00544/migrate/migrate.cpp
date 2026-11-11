#include<bits/stdc++.h>
using namespace std;
int c,T,n,d,f[5010][5010],D[5010][5010],x[2000010];
int read() {
    char ch=getchar();
    int x=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
void write(int x) {
    if(x>9) write(x/10);
    putchar((x%10)+'0');
}
void solve() {
    int ans=0;
    n=read(),d=read();
    for(int i=1;i<=n;i++) x[i]=read();
    for(int i=1;i<=n;i++) for(int j=1;j<i;j++) D[i][j]=1e9,f[i][j]=0;
    for(int i=1;i<=n;i++) {
        for(int j=i-1;x[i]-x[j]<=d&&j>=1;j--) {
            f[i][j]=1,D[i][j]=1;
        }
    }
    for(int len=3;len<=n;len++) {
        for(int j=1,i=len;i<=n;j++,i++) {
            for(int k=j+1;k<i;k++) {
                if(D[i][k]+D[k][j]<D[i][j]) {
                    D[i][j]=D[i][k]+D[k][j];
                    f[i][j]=f[i][k]*f[k][j];
                } else if(D[i][k]+D[k][j]==D[i][j]) {
                    f[i][j]+=f[i][k]*f[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<i;j++) if(f[i][j]==2) ans++;
    cout<<ans<<"\n";
    return ;
}
signed main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--) solve();
    return 0;
}