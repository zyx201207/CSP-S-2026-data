#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int a[N];
int n,d;
int read(){
    int f=1,x=0;
    char ch='\n';
    while(ch<'0'||ch>'9'){
        ch=getchar();
        if(ch=='-') f=-1;
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return f*x;
}
void write(int x){
    if(x<10){
        putchar(x+'0');
        return ;
    }
    write(x/10);
    x%=10;
    putchar(x+'0');
}
void solve(){
    int n,d;
    n=read(),d=read();
//    mp.clear();
    int ans=0;
    for(int i=1;i<=n;i++) a[i]=read();
//    int ans=0;
    for(int i=1;i<=n;i++){
        int r=i+3;
        //cout<<d<<' '<<a[i]<<' '<<a[i+1]<<' '<<a[i+2]<<' '<<a[i+3]<<endl;
        if(r>n) break;
        if(a[i]+d<a[i+2]) continue;
        if(a[i]+d>=a[i+3]||a[i+3]>a[i+1]+d) continue;
        //cout<<111<<endl;
        //cout<<i<<endl;
//        if(a[i]+d<a[i+1]) continue;
        //if(a[i]+d<a[i+2]) continue;
        //if(a[i+1]+d>=a[i+3]) continue;
        //if(a[i]+d>=a[i+3]) continue;
        ans++;
        while(++r<=n&&a[r-2]+d<a[r]&&a[r]<=a[r-1]+d) ans++;
        i=r-4;
    }
    write(ans);
    putchar('\n');
    return ;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _;
//    cout<<(-5)%3;
    _=read();
    _=read();
    while(_--) solve();
    return 0;
}
/*
0 1
6 2
-4 -3 -2 -1 3 6
*/
