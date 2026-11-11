#include <bits/stdc++.h>
#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))),*p1++)
using ll=long long;
using namespace std;
char buf[1<<20],*p1,*p2;
ll read(){
    ll s=0,f=1,c=gc();
    for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
    for(;isdigit(c);c=gc()) s=s*10+(c^48);
    return s*f;
}
const int N=2e6+10;
int c,t;
int a[N];
int dfs(int p){
    for(int i=p+1;i<=n;i++){
        if(a[i]-a[p]>=m){
            if(i+2<=n){
                return n-i-2;
            }
        }
    }
}
int sum;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--){
        int n,d;
        n=read();d=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
        }
        for(int i=1;i<=n;i++){
            sum+=dfs(i);
        }
        cout<<sum<<endl;
    }

    return 0;
}
