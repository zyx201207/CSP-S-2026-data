#include<bits/stdc++.h>
#define int lld
typedef long long lld;
using namespace std;
int c,T,n,d,x[2000006],ans;
namespace D{
    int f[2000006],g[2000006],l,r,mf,mg;
    struct S{
        int f,g,i;
    }que[2000006];
    inline void mn(){
        ans=0;
        for(int i=1;i<=n;i++){
            f[i]=0,g[i]=1,l=1,r=0,mf=0,mg=0;
            for(int j=i+1;j<=n;j++){
                que[++r]={f[j-1],g[j-1],j-1};
                if(que[r].f==mf)mg+=que[r].g;
                while(l<=r&&x[que[l].i]<x[j]-d)
                    mg-=que[l].g,l++;
                if(l<=r){
                    if(mf!=que[l].f){
                        mf=que[l].f,mg=0;
                        for(int k=l;k<=r&&que[k].f==mf;k++)
                            mg+=que[k].g;
                    }
                    f[j]=mf+1,g[j]=mg;
                }else break;
            }
            for(int j=i+1;j<=n;j++)
                ans+=g[j]==2;
        }
    }
}
namespace A{
    inline void mn(){
        int c=x[2]-x[1];
        ans=0;
        for(int i=d/c+1;i<=n;i++){
            int l=c*i-d,r=d;
            if(l<r&&r/c-(l-1)/c==2){
                ans=n-i;
                break;
            }
        }
    }
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&T);
    while(T--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
            scanf("%lld",x+i);
        if(c<=10)D::mn();
        else if(c<=12)A::mn();
        printf("%lld\n",ans);
    }
}