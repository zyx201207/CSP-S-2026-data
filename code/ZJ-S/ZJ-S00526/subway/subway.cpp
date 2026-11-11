#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m,d,q,tot[500005],w[500005];
ll f[505][505],ans;
vector<pair<int,int>>v[500005];
int read(){
    int res=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
    while(isdigit(ch))res=res*10+(ch&15),ch=getchar();
    return res;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    read();n=read();m=read();d=read();q=read();
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++)w[i]=read();
    for(int i=1;i<=n;i++){
        int cnt=read();f[i][i]=0;
        for(int j=1;j<=cnt;j++){
            int x=read(),y=read();v[x].push_back(make_pair(i,y));
            tot[x]++;
        }
    }
    for(int i=1;i<=m;i++)
    for(int j=0;j<tot[i]-1;j++)
    for(int k=j+1;k<tot[i];k++)
    f[v[i][j].first][v[i][k].first]=f[v[i][k].first][v[i][j].first]=min(f[v[i][j].first][v[i][k].first],1ll*v[i][j].second+v[i][k].second);
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x=read(),y=read();ans=LLONG_MAX;
        for(int i=0;i<tot[x];i++)
        for(int j=0;j<tot[y];j++)
        ans=min(ans,1ll*v[x][i].second+v[y][j].second+f[v[x][i].first][v[y][j].first]);
        printf("%lld\n",ans+1ll*w[x]+w[y]);
    }
    return 0;
}