#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N=7e2+10,M=1e6+10;
#define For(a,b,c) for(int a=(b);a<=(LL)(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(LL)(c);a--)

LL INF=0x3f3f3f3f3f3f3f3f;

template <typename T> void tomin(T &a,const T &b){a=a<b?a:b;}
template <typename T> void tomax(T &a,const T &b){a=b<a?a:b;}

template <typename T> void read(T &x){
    T f=0,w=1;
    int ch=getchar();
    while(!isdigit(ch)){if(ch=='-') w=-w;ch=getchar();}
    while(isdigit(ch)) {f=(f<<3)+(f<<1)+ch-48;ch=getchar();}
    x=f*w;
}

int n,m;

LL w[M];
vector <pair<int,LL> > v[N];
vector <pair<int,LL> > d[M];

LL f[N][N];

void awa(){
    int c,q,ddd;
    read(c),read(n),read(m),read(ddd),read(q);
    For(i,1,m) read(w[i]);
    For(i,1,n){
        int m;
        read(m);
        while(m--){
            int a;LL t;
            read(a),read(t);
            v[i].push_back({a,t});
            d[a].push_back({i,t});
        }
    }
    memset(f,0x3f,sizeof(f));
    For(i,1,n) f[i][i]=0;
    For(i,1,n){
        for(auto p:v[i]){
            int a=p.first;
            for(auto q:d[a]){
                int j=q.first;
                tomin(f[i][j],p.second+q.second);
                tomin(f[j][i],p.second+q.second);
            }
        }
    }

    For(k,1,n)
        For(i,1,n)
            For(j,1,n){
                tomin(f[i][j],f[i][k]+f[k][j]);
            }
    
    while(q--){
        int u,v;
        read(u),read(v);
        LL res=INF;
        for(auto d1:d[u]){
            for(auto d2:d[v]){
                tomin(res,d1.second+f[d1.first][d2.first]+d2.second);
            }
        }
        res+=w[u]+w[v];
        printf("%lld\n",res);
    }
}

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int T=1;
    // read(T);
    while(T--) awa();
    cerr<<clock()/1000.0<<"ms\n";
    return 0;
}
/*
Ha, an easy tulun jianmo problem.

baoli dij is O(nqlog), can't 100pts.We want Floyd.And then, why d<=20?

We find that n<=500,can Floyd. For every question, we baoli the subway which can go to the station of query's.

Ha! That's why the station is m,but subway is n. As we all know, we always say |V| is n, |E| is m.

It's O(dm+n^3+qd^2),can 100pts.

So hot! I feel hot...

If I out of kaochang,I feel cold you konw?

I'm hottttt!

emm,why I input Chinses on windows,buy in Linux belike:

��֪��Ϊʲô��Linux �� clock �����һ�� e5 ��������������Ϊ Linux �� clock ���ز��� ms ������

15:46

*/
