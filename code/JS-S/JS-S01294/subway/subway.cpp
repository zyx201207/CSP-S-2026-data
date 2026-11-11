#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,len,x,y,ans,posx,posy,lpx,lpy,ppx,ppy;
int w[1010],k[1010],a[1010][1010],t[1010][1010];
int h[1010],b[1010];
int e[1010][1010];
struct node{
    int dis,p;
};
node px[1010],py[1010];
int read(){
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1; i<=m; i++) w[i]=read();
    for(int i=1; i<=n; i++){
        k[i]=read();
        for(int j=1; j<=k[i]; j++){
            a[i][j]=read(),t[i][j]=read();
            h[a[i][j]]++;
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=m; j++){
            e[i][j]=1e18;
        }
        e[i][i]=0;
    }
    for(int i=1; i<=n; i++){
        len=0;
        for(int j=1; j<=k[i]; j++){
            if(h[a[i][j]]>=2) b[++len]=j;
        }
        for(int j=1; j<len; j++){
            for(int k=j+1; k<=len; k++){
                int u=a[i][b[j]],v=a[i][b[k]];
                e[u][v]=min(e[u][v],t[i][b[j]]+t[i][b[k]]),e[v][u]=e[u][v];
            }
        }
    }
    for(int k=1; k<=m; k++){
        for(int i=1; i<=m; i++){
            for(int j=1; j<=m; j++){
                e[i][j]=min(e[i][j],e[i][k]+e[k][j]);
            }
        }
    }
    // for(int i=1; i<=m; i++){
    //     for(int j=1; j<=m; j++) cout<<setw(20)<<e[i][j];
    //     cout<<endl;
    // }
    while(q--){
        x=read(),y=read();
        ans=w[x]+w[y];
        if(h[x]==1){
            posx=0,lpx=0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=k[i]; j++){
                    if(a[i][j]==x){
                        posx=i,ppx=j;
                        break;
                    }
                }
                if(posx) break;
            }
            for(int i=1; i<=k[posx]; i++){
                if(h[a[posx][i]]>=2) px[++lpx].p=a[posx][i],px[lpx].dis=t[posx][ppx]+t[posx][i];
            }
        }
        if(h[y]==1){
            posy=0,lpy=0;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=k[i]; j++){
                    if(a[i][j]==y){
                        posy=i,ppy=j;
                        break;
                    }
                }
                if(posy) break;
            }
            for(int i=1; i<=k[posy]; i++){
                if(h[a[posy][i]]>=2) py[++lpy].p=a[posy][i],py[lpy].dis=t[posy][ppy]+t[posy][i];
            }
        }
        if(h[x]>=2&&h[y]>=2) ans+=e[x][y];
        else if(h[x]==1&&h[y]>=2){
            int minn=1e18;
            for(int i=1; i<=lpx; i++) minn=min(minn,e[px[i].p][y]+px[i].dis);
            ans+=minn;
        }
        else if(h[x]>=2&&h[y]==1){
            int minn=1e18;
            for(int i=1; i<=lpy; i++) minn=min(minn,e[py[i].p][x]+py[i].dis);
            ans+=minn;
        }
        else{
            int minn=1e18;
            for(int i=1; i<=lpx; i++){
                for(int j=1; j<=lpy; j++){
                    minn=min(minn,e[px[i].p][py[j].p]+px[i].dis+py[j].dis);
                }
            }
            if(posx==posy) minn=min(minn,t[posx][ppx]+t[posy][ppy]);
            ans+=minn;
        }
        cout<<ans<<endl;
    }
    return 0;
}