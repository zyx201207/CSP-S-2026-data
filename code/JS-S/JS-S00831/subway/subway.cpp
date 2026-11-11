#include<bits/stdc++.h>
using namespace std;
int c,n,m,dd,q,x,y,k[511],nws,stw[514114],tp;
vector<long long> t[511],tot[514114];
vector<int> a[511],to[514114];
long long w[514114],d[511][511],ans;
long long rd(){
    char c=getchar_unlocked();
    long long ans=0;
    while(c<'0'||c>'9')c=getchar_unlocked();
    while(c>='0'&&c<='9')ans=(ans<<3)+(ans<<1)+(c^48),c=getchar_unlocked();
    return ans;
}int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=rd(),n=rd(),m=rd(),dd=rd(),q=rd();
    for(int i=1;i<=m;i++)w[i]=rd();
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=!!(i-j)*2e12;
    for(int i=1;i<=n;i++){k[i]=rd();for(int j=1;j<=k[i];j++)x=rd(),y=rd(),a[i].push_back(x),t[i].push_back(y),to[x].push_back(i),tot[x].push_back(y),stw[x]++;}
    for(int i=1;i<=n;i++)for(int j=0;j<k[i];j++){
        nws=a[i][j];
        for(int h=0;h<stw[nws];h++){tp=to[nws][h];if(tp-i)d[i][tp]=min(d[i][tp],t[i][j]+tot[nws][h]);}
    }for(int k=1;k<=n;k++)for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    while(q--){
        x=rd(),y=rd(),ans=2e12;
        for(int i=0;i<stw[x];i++)for(int j=0;j<stw[y];j++)ans=min(ans,d[to[x][i]][to[y][j]]+tot[x][i]+tot[y][j]);
        printf("%lld\n",ans+w[x]+w[y]);
    }return 0;
}
