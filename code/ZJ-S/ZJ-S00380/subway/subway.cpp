#include<bits/stdc++.h>
#define int long long
using namespace std;

namespace YJR{
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
    while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int n,m,d,q,val[500005],dis[505][505];
int frm[500005][22];
unordered_map<int,int> cst[505];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) val[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int x=read(),t=read();
            cst[i][x]=t;
            frm[x][++frm[x][0]]=i;
        }
    }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++) dis[i][i]=0;
    for(int i=1;i<=n;i++)
        for(auto it:cst[i])
            for(int j=1;j<=frm[it.first][0];j++)
                dis[i][frm[it.first][j]]=dis[frm[it.first][j]][i]=min(dis[i][frm[it.first][j]],it.second+cst[frm[it.first][j]][it.first]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) if(i!=j)
    for(int k=1;k<=n;k++)
        dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int i=1;i<=q;i++){
        int x=read(),y=read(),ans=1e18;
        for(int xi=1;xi<=frm[x][0];xi++)
        for(int yi=1;yi<=frm[y][0];yi++) ans=min(ans,val[x]+val[y]+cst[frm[x][xi]][x]+cst[frm[y][yi]][y]+dis[frm[x][xi]][frm[y][yi]]);     
        cout<<ans<<endl;
    }
    // cerr<<clock()*1.0/CLK_TCK;
    return 0;
}
}

signed main(){return YJR::main();}
//g++ subway.cpp -o subway -O2 -std=c++14 -static