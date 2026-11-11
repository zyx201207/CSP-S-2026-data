#include <bits/stdc++.h>
#define BIG
// #define MID
#ifdef BIG
#define int __int128
#endif
#ifdef MID
#define int long long
#endif
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],c[N];
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
inline int solve(int x){
    int tot=0;
    for(int i=1;i<=n;i++)
        if(a[i]<=x)b[++tot]=x-a[i];else break;
    reverse(b+1,b+tot+1);int sum=0,ans=0;
    for(int i=1;i<=tot;i++)
        if(sum+b[i]<=m)sum+=b[i],ans++;
    return ans;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=c[i]=read();
    sort(a+1,a+n+1),sort(c+1,c+n+1);
    int N=unique(c+1,c+n+1)-c-1,L=1,R=N;
    while(L<=R){
        int mid=L+R>>1;
        if(solve(c[mid])<solve(c[mid+1]))L=mid+1;
        else R=mid-1;
    }
    writeln(max(solve(c[L]),solve(c[R])));
    return 0;
}