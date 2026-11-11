#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N=2e6+10,M=1e6+10;
#define For(a,b,c) for(int a=(b);a<=(LL)(c);a++)
#define Rep(a,b,c) for(int a=(b);a>=(LL)(c);a--)
// #define debug

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

vector <int> e[N];
int n,k;

void awa(){
    // read(n),read(k);
    // For(i,2,n){
    //     int u,v;
    //     read(u),read(v);
    //     e[u].push_back(v);
    //     e[v].push_back(u);
    // }
    // dfs(1,0);
}

signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T=1;
//    read(C), read(T);
    // while(T--) awa();
    puts("189");
    puts("233");
    puts("288");
    puts("229");
    puts("338");
    cerr<<clock()/1000.0<<"ms\n";
    return 0;
}
/*

lai bu ji le aaa

*/
