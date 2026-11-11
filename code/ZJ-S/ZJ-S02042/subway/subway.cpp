#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int getint(){
    int x=0;
    char ch=getchar();
    while(!(ch>='0'&&ch<='9')) ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x;
}
int head[550006],vet[550006],dg[550006],val[550006],ed;
int g[550006],h[550006],b[550006];
int w[500005];
long long f[505][505];
void putint(long long x){
    if(x<10){
        putchar(x+'0');
        return;
    }
    putint(x/10);
    putchar(x%10+'0');
}
int main(){
    // double st=clock();
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=getint();n=getint();m=getint();d=getint();q=getint();
    for(int i=1;i<=m;i++){
        w[i]=getint();
    }
    int cnt=0;
    int mx=0;
    for(int i=1;i<=n;i++){
        int k=getint();
        while(k--){
            cnt++;
            g[cnt]=getint();
            b[cnt]=getint();
            h[cnt]=i;
            head[g[cnt]]++;
            mx=max(mx,head[g[cnt]]);
        }
    }
    for(int i=1;i<=m+1;i++){
        head[i]=head[i-1]+head[i];
    }
    for(int i=1;i<=cnt;i++){
        vet[head[g[i]]]=h[i];
        val[head[g[i]]]=b[i];
        head[g[i]]--;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) f[i][j]=0;
            else f[i][j]=1e18;
        }
    }
    // cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
    for(int i=1;i<=m;i++){
        for(int e=head[i]+1;e<=head[i+1];e++){
            int v=vet[e],z=val[e];
            for(int x=head[i]+1;x<=head[i+1];x++){
                int u=vet[x],y=val[x];
                f[u][v]=min(f[u][v],1ll*z+y);
                f[v][u]=min(f[v][u],1ll*z+y);
                // for(int k=100+e%10;k;k--){
                //     u^=y;
                //     y+=k;
                //     u=min(u,v);
                // }
                // putint(u);
            }
        }
    }
    // cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    // cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
    // long long su=0;
    while(q--){
        int u,v;
        u=getint();
        v=getint();
        long long ans=1e18;
        for(int x=head[u]+1;x<=head[u+1];x++){
            for(int y=head[v]+1;y<=head[v+1];y++){
                ans=min(ans,1ll*val[x]+1ll*val[y]+f[vet[x]][vet[y]]);
                // int bb=x+y;
                // for(int k=100+(x+y)%10;k;k--){
                //     bb^=k;
                // }
                // su+=bb;
            }
        }
        putint(ans+w[u]*1ll+w[v]*1ll);
        putchar('\n');
    }
    // cout<<su<<endl;
    // cerr<<(clock()-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}
//-Wall -Wextra -Wpedantic -Wshadow -Wconversion -fno-ms-extensions