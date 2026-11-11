#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
int a[N],f[N];
int f0[32][N];
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x<10){putchar(x+48);return;}
    else{write(x/10);putchar(x%10+48);}
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;n=read();m=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
        int j=1,h=0;
        while(j<=a[i]){
            if(a[i]&j){f0[h][i]=1;}
            j<<=1;h++;
        }   
    }
    memset(f,1,sizeof(f));
    int ans=0;
    for(int j=30;j>=0;j--){
        int cnt1=0;
        for(int i=1;i<=n;i++)
            if(f[i]&&f0[j][i]) cnt1++;
        if(cnt1<m) continue;
        ans+=(1<<j);
        for(int i=1;i<=n;i++)
            if(!f0[j][i]) f[i]=0;
    }
    write(ans);
    return 0;
}