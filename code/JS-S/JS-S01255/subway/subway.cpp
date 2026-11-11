#include<bits/stdc++.h>
#define int long long
#define get() getchar()
#define put(ch) putchar(ch)
using namespace std;
inline int read(){int x=0,f=1;char ch=get();while(ch!=EOF&&(ch<'0'||ch>'9')){if(ch=='-')f=-1;ch=get();}while(ch>='0'&&ch<='9')x=x*10+(ch^'0'),ch=get();return x*f;}
inline void write(int x){if(x<0)put('-'),x=-x;if(x>=10)write(x/10);put((x%10)^'0');}
struct Node{
    int i,t;
}fr[500005][20];
int w[500005],cnt[500005],l[505][505],minn[505][505],vi[505];
void main1(){
    memset(l,0x3f,sizeof(l));
    memset(minn,0x3f,sizeof(minn));
    int c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;++i){
        w[i]=read();
    }
    for(int i=1;i<=n;++i){
        int k=read();
        for(int j=1;j<=k;++j){
            int x=read(),t=read();
            fr[x][++cnt[x]]={i,t};
        }
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=cnt[i];++j){
            for(int k=1;k<j;++k){
                int num=fr[i][j].t+fr[i][k].t;
                if(num<l[fr[i][j].i][fr[i][k].i]){
                    l[fr[i][j].i][fr[i][k].i]=l[fr[i][k].i][fr[i][j].i]=num;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        minn[i][i]=0;
        for(int j=1;j<=n;++j){
            vi[j]=0;
        }
        for(int j=1;j<=n;++j){
            int mi=0;
            for(int k=1;k<=n;++k){
                if(vi[k]==0 && minn[i][k]<minn[i][mi]){
                    mi=k;
                }
            }
            vi[mi]=1;
            int num=minn[i][mi];
            for(int k=1;k<=n;++k){
                int nm=num+l[mi][k];
                if(nm<minn[i][k]){
                    minn[i][k]=nm;
                }
            }
        }
    }
    for(int i=1;i<=q;++i){
        int x=read(),y=read(),ans=0x3f3f3f3f3f3f3f3f;
        for(int j=1;j<=cnt[x];++j){
            for(int k=1;k<=cnt[y];++k){
                ans=min(ans,fr[x][j].t+fr[y][k].t+minn[fr[x][j].i][fr[y][k].i]);
            }
        }
        write(ans+w[x]+w[y]);
        put('\n');
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int t=1;
    while(t--){
        main1();
    }
    return 0;
}
