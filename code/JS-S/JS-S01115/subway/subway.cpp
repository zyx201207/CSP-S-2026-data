#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,i,i3,i2,ans,rin;
int w[500005];
long long p[505][505];
int plata[500005][22];
int platt[500005][22];
int num[500005];
long long minl[505][505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    memset(p,127,sizeof(p));
    for(i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    int a1,t1;
    for(i=1;i<=n;i++){
        scanf("%lld",&k);
        for(i2=1;i2<=k;i2++){
            scanf("%d%d",&a1,&t1);
            num[a1]++;
            plata[a1][num[a1]]=i;
            platt[a1][num[a1]]=t1;
        }
    }
    for(i=1;i<=m;i++){
        a1=num[i];
        for(i2=1;i2<a1;i2++){
            for(i3=i2+1;i3<=a1;i3++){
                rin=platt[i][i2]+platt[i][i3];
                if(p[plata[i][i2]][plata[i][i3]]>rin){
                    p[plata[i][i2]][plata[i][i3]]=rin;
                    p[plata[i][i3]][plata[i][i2]]=rin;
                }
            }
        }
    }
    long long s,sss;
    long long dd[505];
    bool b[505]={};
    for(i=1;i<n;i++){
        s=i;
        memset(dd,127,sizeof(dd));
        memset(b,0,sizeof(b));
        dd[s]=0;
        b[s]=1;
        for(i2=1;i2<n;i2++){
            for(i3=1;i3<=n;i3++){
                dd[i3]=min(dd[i3],dd[s]+p[s][i3]);
            }
            sss=8000000000000000000;
            for(i3=1;i3<=n;i3++){
                if(b[i3]==0){
                    if(dd[i3]<sss){
                        s=i3;
                        sss=dd[i3];
                    }
                }
            }
            b[s]=1;
        }
        for(i2=1;i2<=n;i2++){
            minl[i][i2]=dd[i2];
            minl[i2][i]=dd[i2];
        }
    }

    int x,y,x1,y1;
    for(i=1;i<=q;i++){
        scanf("%d%d",&x,&y);
        ans=8000000000000000000;
        x1=num[x];
        y1=num[y];
        for(i2=1;i2<=x1;i2++){
            for(i3=1;i3<=y1;i3++){
                ans=min(ans,minl[plata[x][i2]][plata[y][i3]]+platt[x][i2]+platt[y][i3]);
            }
        }
        ans+=w[x]+w[y];
        printf("%lld\n",ans);
    }
    return 0;
}
