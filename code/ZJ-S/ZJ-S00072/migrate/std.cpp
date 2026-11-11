#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=2e3+3;
int n,fa[N];
ll d,a[N],f[N][N],dis[N][N];
void _main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    fa[n+1]=n;
    for(int i=n;i>=1;i--){
        fa[i]=fa[i+1];
        while(a[fa[i]]-a[i]>d)fa[i]--;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        queue<int>q;
        memset(dis[i],0x3f,sizeof(dis[i])),memset(f[i],0,sizeof(f[i]));
        q.push(i),f[i][i]=1,dis[i][i]=0;
        while(!q.empty()){
            int x=q.front();q.pop();
            for(int j=x+1;j<=fa[x];j++){
                if(dis[i][j]==0x3f3f3f3f3f3f3f3f)dis[i][j]=dis[i][x]+1,q.push(j);
                if(dis[i][j]==dis[i][x]+1)f[i][j]+=f[i][x];
            }
        }
        for(int j=i;j<=n;j++)if(f[i][j]==2)ans++;
        for(int j=i;j<=n;j++)if(f[i][j]==2)cout<<i<<' '<<j<<'\n';
    }
    cout<<ans<<'\n';
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,t=1;cin>>c>>t;
    while(t--)_main();
    clock_t _ed=clock();
    cerr<<(_ed-_st)*1.0/CLOCKS_PER_SEC<<'\n';
    return 0;
}
/*
g++ std.cpp -o std -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ std.cpp -o std -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/