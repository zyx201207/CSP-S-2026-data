/*
宇宙冷漠，这张牌我是，非常了解的。
*/
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=5e5;
int w[N+5];
vector<pair<int,int> > gph[N+5];
long long dis[505][505];
void read(int &x){
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    if(f) x=-x;
}
void write(long long x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10) write(x/10);
    putchar(x%10+'0');
}
void solve(){
    read(c);
    read(n);
    read(m);
    read(d);
    read(q);
    for(int i=1;i<=m;++i){
        read(w[i]);
    }
    for(int i=1;i<=n;++i){
        int ki;
        read(ki);
        for(int j=1;j<=ki;++j){
            int aij,tij;
            read(aij);read(tij);
            gph[aij].emplace_back(i,tij);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e18;
        }
    }
    for(int i=1;i<=m;++i){
        for(int j=0;j<gph[i].size();++j){
            for(int k=j+1;k<gph[i].size();++k){
                dis[gph[i][j].first][gph[i][k].first]=dis[gph[i][k].first][gph[i][j].first]=min(dis[gph[i][k].first][gph[i][j].first],(long long)gph[i][j].second+gph[i][k].second);
            }
        }
    }
    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        int u,v;
        read(u),read(v);
        long long ans=1e18;
        for(auto [j,t1]:gph[u]){
            for(auto [k,t2]:gph[v]){
                ans=min(ans,dis[j][k]+t1+t2);
            }
        }
        write(ans+w[u]+w[v]);
        putchar('\n');
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // ios::sync_with_stdio(0);cin.tie(0);
    int Tcases=1;
    // cin>>Tcases;
    while(Tcases--) solve();
    return 0;
}
/*
在古代，穷人一拳打倒十个保安到底有多爽。


*/