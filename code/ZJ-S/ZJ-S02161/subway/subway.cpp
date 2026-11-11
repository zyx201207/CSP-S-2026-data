#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,x,y) for(int (i)=(x);(i)<=(y);++i)
const ll N=500+10;
const ll M=5e5+10;

ll c,n,m,d,q,f[N][N],a[M],cnt[M];
ll g[M][25],t[M][25];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    memset(f,0x3f,sizeof(f));
    cin>>c>>n>>m>>d>>q;
    rep(i,1,m) cin>>a[i];
    for(int s,i=1;i<=n;++i){
        cin>>s;
        for(int id,w,j=1;j<=s;++j){
            cin>>id>>w;
            cnt[id]++;
            g[id][cnt[id]]=i;
            t[id][cnt[id]]=w;
        }
    }
    for(int i=1;i<=m;++i){
        for(int f1=1;f1<=cnt[i];++f1){
            for(int f2=1;f2<f1;++f2){
                int x=g[i][f1],y=g[i][f2];
                f[x][y]=min(f[x][y],t[i][f1]+t[i][f2]);
                f[y][x]=min(f[y][x],t[i][f1]+t[i][f2]);
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            for(int k=1;k<=n;++k){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    rep(i,1,n) f[i][i]=0;
    for(int st,ed,i=1;i<=q;++i){
        cin>>st>>ed;
        ll minn=0x3f3f3f3f3f3f3f3f;
        for(int f1=1;f1<=cnt[st];++f1){
            for(int f2=1;f2<=cnt[ed];++f2){
                minn=min(minn,f[g[st][f1]][g[ed][f2]]+t[st][f1]+t[ed][f2]);
            }
        }
        cout<<minn+a[st]+a[ed]<<'\n';
    }
    return 0;
}