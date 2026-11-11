#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+10;
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0) {putchar('-');x=-x;}
    if(x<10){putchar(x+'0');return;}
    else {write(x/10);putchar(x%10+'0');}
}
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;c=read();t=read();
    while(t--){
        int n,m;n=read();m=read();
        for(int i=1;i<=n;i++) a[i]=read();
        if(c==11||c==12){
            if(n==1) {
                cout<<0<<'\n';
                for(int i=1;i<=n;i++) a[i]=0;
                continue;
            }
            int cnt=a[2]-a[1];
            int cnt1=m/cnt;
            if(cnt1<=1){
                for(int i=1;i<=n;i++) a[i]=0;
                cout<<0<<'\n';continue;
            }
            cout<<n-cnt1-1<<'\n';
            for(int i=1;i<=n;i++) a[i]=0;
            continue; 
        }
    }
    return 0;
}