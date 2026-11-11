#include<bits/stdc++.h>
using namespace std;
const int N=500001;
int g[N],b[N][501],e[N],l[N][501],p[501][501],r[501];
int c,n,m,d,q,x,y;
int res;
void f(int z,int re){
    if (r[z]) return;
    for (int i=1;i<=e[y];i++){
        if (z==l[y][i]){
            if (res==0) res=re+b[y][z];
            else res=min(res,re+b[y][z]);
            break;
        }
    }
    for (int i=1;i<=n;i++){
        if (i!=z && p[z][i]!=0){
            f(i,re+p[z][i]);
        }
    }
}
void f1(int z,int w){
    if (r[z]) return;
    for (int i=1;i<=e[y];i++){
        if (z==l[y][i]){
            if (res==0) res=w+1;
            else res=min(res,w+1);
            break;
        }
    }
    for (int i=1;i<=n;i++){
        if (i!=z && p[z][i]!=0){
            f(i,w+2);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=1;i<=m;i++) cin>>g[i];
    for (int i=1;i<=n;i++){
        int k;
        cin>>k;
        for (int j=1;j<=k;j++){
            int a,t;
            cin>>a>>t;
            b[a][i]=t;
            for (int o=1;o<e[a];o++){
                /*if ((b[a][i]+b[a][l[a][e[o]]]<p[i][l[a][e[o]]]) || (p[i][l[a][e[o]]]==0)) {
                    p[i][l[a][e[o]]]=b[a][i]+b[a][l[a][e[o]]];
                    p[l[a][e[o]]][i]=b[a][i]+b[a][l[a][e[o]]];
                }*/
                p[i][l[a][e[o]]]=1;
                p[l[a][e[o]]][i]=1;
            }
            e[a]++;
            l[a][e[a]]=i;
        }
    }
    if (c>=12 && c<=19){
        for(int i=1;i<=q;i++){
            int ans=0;
            res=0;
            cin>>x>>y;
            ans=g[x]+g[y];
            for(int j=1;j<=e[x];j++){
                f1(l[x][j],1);
                for (int o=1;o<=n;o++) r[o]=0;
            }
            ans+=(res*b[1][l[1][1]]);
            cout<<ans<<"\n";
        }
    }
    for(int i=1;i<=q;i++){
        int ans=0;
        res=0;
        cin>>x>>y;
        ans=g[x]+g[y];
        for(int j=1;j<=e[x];j++){
            f(l[x][j],b[x][l[x][j]]);
            for (int o=1;o<=n;o++) r[o]=0;
        }
        ans+=res;
        cout<<ans<<"\n";
    }
    return 0;
}
