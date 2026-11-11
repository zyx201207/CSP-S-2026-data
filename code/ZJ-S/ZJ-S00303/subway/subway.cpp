#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define PII pair<int,int>
#define PIL pair<int,ll>
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int read(){
    char c = ' ';int x = 0;
    while(c<'0' || c>'9')c = getchar();
    while(c>='0' && c<='9')x = x*10+c-'0',c = getchar();
    return x;
}
int C,n,m,d,q;
ll w[500003],dis[503][503];
vector<PIL>sta[500003];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    C = read();n = read();m = read();d = read();q = read();
    for(int i = 1;i<=m;i++)w[i] = read();
    for(int i = 1;i<=n;i++){
        int k = read();
        while(k--){
            int a = read();
            int t = read();
            sta[a].push_back({i,t});
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i = 1;i<=n;i++)dis[i][i] = 0;
    for(int i = 1;i<=m;i++)
        for(auto x:sta[i])
            for(auto y:sta[i])
                dis[x.fi][y.fi] = min(dis[x.fi][y.fi],x.se+y.se);
    for(int k = 1;k<=n;k++)
        for(int i = 1;i<=n;i++)
            for(int j = 1;j<=n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--){
        int x = read();
        int y = read();
        ll ans = INF;
        for(auto i:sta[x])
            for(auto j:sta[y])
                ans = min(ans,dis[i.fi][j.fi]+i.se+j.se);
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
/*
g++ -o subway/subway subway/subway.cpp -O2 -std=c++14 -static -Wall -Wshadow
*/