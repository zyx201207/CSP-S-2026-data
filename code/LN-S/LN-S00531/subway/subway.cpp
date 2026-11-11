#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int c,n,m,d,q;
long long w[500010],f[510][510],ans;
vector<pair<int,long long> > a[500010];
long long read_ll(){
    long long x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar_unlocked();
    }
    return x*f;
}
int read_int(){
   int x=0,f=1;
    char ch=getchar_unlocked();
    while(ch<'0' || ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
    }
    while(ch>='0' && ch<='9'){
        x=x*10+ch-'0';
        ch=getchar_unlocked();
    }
    return x*f;
}
long long write(long long x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read_int();
    n=read_int();
    m=read_int();
    d=read_int();
    q=read_int();
    for(int i=1;i<=m;++i){
        w[i]=read_ll();
    }
    int k,x;
    long long t;
    for(int i=1;i<=n;++i){
        k=read_int();
        while(k--){
            x=read_int();
            t=read_ll();
            a[x].push_back(make_pair(i,t));
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            f[i][j]=inf;
        }
        f[i][i]=0;
    }
    int u,v;
    for(int i=1;i<=m;++i){
        for(int j=0;j<a[i].size();++j){
            u=a[i][j].first;
            for(int k=0;k<j;++k){
                v=a[i][k].first;
                f[v][u]=f[u][v]=min(f[u][v],a[i][j].second+a[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<i;++j){
                f[j][i]=f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(q--){
        u=read_int();
        v=read_int();
        ans=inf;
        for(int i=0;i<a[u].size();++i){
            for(int j=0;j<a[v].size();++j){
                ans=min(ans,a[u][i].second+a[v][j].second+f[a[u][i].first][a[v][j].first]);
            }
        }
        write(ans+w[u]+w[v]);
        putchar('\n');
    }
    return 0;
}

