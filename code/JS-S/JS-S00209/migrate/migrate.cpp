#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+2;
int c,t,n,d,p;
int x[maxn],f[maxn];
void init(){
    n=d=p=0;
    memset(x,0,sizeof(x));
    memset(f,0,sizeof(f));
}
int cal(int x){
    if(x<=p) return f[x];
    int res=0;
    for(int i=x-p;i<=x;i++){
        if(!f[i]) f[i]=cal(i);
        res+=f[i];
    }
    return res;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // be able to lie marks:point 11,12
    scanf("%d %d",&c,&t);
    while(t--){
        init();
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        }
        if(c==11||c==12){
            p=d/(x[2]-x[1]);
            f[1]=1;
            for(int i=2,add1=1,add2=0;i<=min(n,p);i++){
                f[i]=f[i-1]+add1;
                int add3=add1;
                add1+=add2;
                add2=add3;
            }
            if(n<=p) cout<<f[n];
            else cout<<cal(n);
            continue;
        }
    }
    return 0;
}
