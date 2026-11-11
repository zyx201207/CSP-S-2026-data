#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define max_eq(a,b) ((a)=(a)>(b)? (a):(b))
#define min_eq(a,b) ((a)=(a)<(b)? (a):(b))
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()

const int N=505,M=5e5+5;

ll f[N][N],a[M];
vector<pair<int,int>> out[M];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int cas,n,m,d,q;
    scanf("%d%d%d%d%d",&cas,&n,&m,&d,&q);
    F(i,1,m) scanf("%lld",&a[i]);
    F(i,1,n){
        int k;
        scanf("%d",&k);
        while(k--){
            int x,t;
            scanf("%d%d",&x,&t);
            out[x].eb(i,t);
        }
    }
    memset(f,0x3f,sizeof(f));
    F(i,1,n) f[i][i]=0;
    F(i,1,m){
        sort(all(out[i]));
        for(auto [v1,w1]:out[i]){
            for(auto [v2,w2]:out[i]){
                if(v2>=v1) break;
                f[v1][v2]=f[v2][v1]=min(f[v1][v2],(ll)w1+w2);
            }
        }
    }
    F(k,1,n) F(i,1,n) F(j,1,n)
        min_eq(f[i][j],f[i][k]+f[k][j]);
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=LLONG_MAX/2;
        for(auto [p,w1]:out[x]){
            for(auto [q,w2]:out[y]){
                // cerr<<x<<' '<<y<<' '<<p<<' '<<q<<' '<<a[x]+a[y]+w1+w2+f[p][q]<<endl;
                min_eq(ans,a[x]+a[y]+w1+w2+f[p][q]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

// g++ subway.cpp -o subway -std=c++14 -O2 -Wall -Wextra -Wshadow -Wconversion -fsanitize=address,undefined
// ulimit -s 524288
// /usr/bin/time -v ./my
// g++ subway.cpp -o subway -std=c++14 -O2 -Wall