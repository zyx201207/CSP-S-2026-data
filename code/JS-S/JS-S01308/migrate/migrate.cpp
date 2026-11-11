#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
inline int read(){
    int x=0;
    bool b=1;
    char c=getchar_unlocked();
    while(c<'0'||c>'9'){
        if(c=='-')b=0;
        c=getchar_unlocked();
    }while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar_unlocked();
    }return b?x:~(x-1);
}int n,m,a[N],T,o;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    o=read();T=read();
    while(T--){
        n=read();m=read();
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)a[i]=read();
        if(n<4){
            printf("0\n");
            continue;
        }
        a[n]=a[n-1]+m+1;
        int ans=0;
        for(int i=0;i<n;i++){
            int x=upper_bound(a,a+n+1,a[i]+m)-a;
            if(x==n)break;
            if(x-i<2)continue;
            if(a[x]-a[x-2]>m)continue;
            if(x-i>3)if(a[x]-a[x-3]<=m)continue;
            int r=upper_bound(a,a+n,a[x-2]+m)-a-1;
            int s=1;
   //         cout<<i<<' '<<x<<' '<<r<<"\n";
            for(int j=i-1;j>=0;j--){
                if(a[i]-a[j]>m)break;
                if(a[i+1]-a[j]<=m)break;
                if(j>0) if(a[i]-a[j-1]<=m)break;
                s++;
            }for(int y=x;y<=r;y++){
                for(int j=y+1;j<n;j++){
                    if(a[j]-a[y]>m)break;
                    if(a[j]-a[y-1]<=m)break;
                    if(j<n-1) if(a[j+1]-a[y]<=m)break;
                    ans+=s;
                }ans+=s;
            }
        }printf("%lld\n",ans);
    }
    return 0;
}