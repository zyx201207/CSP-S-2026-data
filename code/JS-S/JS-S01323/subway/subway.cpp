#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int read(){
    int s=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {s=s*10+c-48;c=getchar();}
    return s*f;
}
void write(int x){
    if(x<0) {putchar('-');x=-x;}
    if(x<10){putchar(x+'0');return;}
    else {write(x/10);putchar(x%10+'0');}
}
int f[505][505],w[N],c,n,m,d,q;
vector<pair<int,int> > a[N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k;k=read();
        for(int j=1;j<=k;j++){
            int x,y;x=read();y=read();
            a[x].push_back({i,y});
        }
    }memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=m;i++){
        for(int t1=0;t1<a[i].size();t1++){
            for(int t2=0;t2<a[i].size();t2++){
                if(t1==t2) continue;
                int x=a[i][t1].first,y=a[i][t2].first,l=a[i][t1].second+a[i][t2].second;
                f[x][y]=min(f[x][y],l);
            }
        }
    }
    
    for(int i=1;i<=n;i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
                f[x][y]=min(f[x][i]+f[i][y],f[x][y]);
    for(int i=1;i<=q;i++){
        int x,y;cin>>x>>y;
        int ans=LONG_LONG_MAX;
        for(int t1=0;t1<a[x].size();t1++)
            for(int t2=0;t2<a[y].size();t2++)
                 ans=min(ans,f[a[x][t1].first][a[y][t2].first]+a[x][t1].second+a[y][t2].second);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}