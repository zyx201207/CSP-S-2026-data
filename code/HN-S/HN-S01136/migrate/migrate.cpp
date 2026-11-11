#include<bits/stdc++.h>
#define mid (l+((r-l)>>1))
#define ls (p<<1)
#define rs (ls|1)
#define lt ls,l,mid
#define rt rs,mid+1,r
#define ll long long
#define int long long
using namespace std;
const int N=1e6+5,M=505;
int a[N];

inline int read(){
    int a=1,b=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') a=-a;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        b=(b<<1)+(b<<3)+(ch^48);
        ch=getchar();
    }
    return a*b;
}



signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=read(),T=read();
    if(c==11||c==12){
        while(T--){
            int n=read(),d=read();
            for(int i=1;i<=n;i++) a[i]=read();
            if(n<=3){puts("0");continue;}
            int de=d/(a[2]-a[1]);
            if(de<=1){puts("0");continue;}
            de=de*2-1;
            printf("%lld\n",max(0ll,n-de));
            // int l=1,r=0;
            // while(r!=n){
            //     r++;

            // }
        }
        return 0;
    }
    else if(c==13||c==14){
        while(T--){
            int n=read(),d=read();
            for(int i=1;i<=n;i++) a[i]=read();
            if(n<=3){puts("0");continue;}
            // for(int i=1;i<=n;i++) l1[i]=l2[i]=r1[i]=r2[i]=0;
            int r=1;
            // for(int i=1;i<=n;i++) cout<<a[i]-a[1]<<" "<<d<<endl;;cout<<endl;
            while(a[r]-a[1]<=d&&r!=n) r++;
            cout<<r<<endl;
            if(a[r]-a[1]<=d){puts("0");continue;}
            if(r<=3) {puts("0");continue;}
            r--;
            int lcnt=0,rcnt=0;
            for(int i=1;i<r-1;i++){
                if(a[r+1]-a[i]>d&&a[r]-a[i]<=d&&a[r-1]-a[i]<=d) lcnt++;
            }
            for(int i=r+1;i<=n;i++){
                if(a[i]-a[r-2]>d&&a[i]-a[r-1]<=d&&a[i]-a[r]<=d) rcnt++;
            }
            printf("%lld\n",lcnt*rcnt);
        }
    }
    // while(T--){
    //     int n=read(),d=read();
    //     for(int i=1;i<=n;i++) a[i]=read();
    //     for(int i=1;i<=n;i++){
    //         dis[i][i]=0;
    //         int lst=i,now=1；
    //         for(int j=i;j<=n;j++){
    //             if(a[j]-a[lst]>d) now++;
    //             dis[j][i]=dis[i][j]=now;
    //         }
    //     }
    //     for(int i=1;i<=n-3;i++){
    //         if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d&&a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+3]-a[i]>d) jl
    //     }
    // }
    return 0;
}