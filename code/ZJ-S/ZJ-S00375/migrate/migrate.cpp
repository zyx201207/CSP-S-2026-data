#include <bits/stdc++.h>
// #define BIG
#define MID
#ifdef BIG
#define int __int128
#endif
#ifdef MID
#define int long long
#endif
using namespace std;
const int N=5e3+5;
int T,n,d,a[N],pre[N],f[N],c[N];
inline int read(){
    int ret=0,f=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
    while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
    return ret*f;
}
inline void write(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
inline void writesp(int x){write(x),putchar(' ');}
inline void writeln(int x){write(x),putchar('\n');}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read(),T=read();
    while(T--){
        n=read(),d=read();int ans=0;
        for(int i=1;i<=n;i++)a[i]=read(),pre[i]=0;
        for(int i=1,j=1;i<=n;i++){
            for(;j<n&&a[j+1]-a[i]<=d;j++)
                if(!pre[j])pre[j]=i;
            if(!pre[j])pre[j]=i;
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++)f[j]=1e9,c[j]=0;f[i]=0,c[i]=1;
            for(int j=i+1;j<=n;j++){
                int lst=max(i,pre[j]);
                for(int k=lst;k<j;k++){
                    if(f[j]>f[k]+1)f[j]=f[k]+1,c[j]=c[k];else if(f[j]==f[k]+1)c[j]+=c[k];else break;
                    if(c[j]>2)break;
                }
                if(c[j]==2)ans++;
            }
        }
        writeln(ans);
    }
    return 0;
}