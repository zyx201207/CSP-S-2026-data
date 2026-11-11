#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=2e3+3;
int n,to[N];
ll d,a[N],dis[N][N];
void _main(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(dis,-1,sizeof(dis));
    to[n+1]=n;
    for(int i=n;i>=1;i--){
        dis[i][i]=0,to[i]=to[i+1];
        while(a[to[i]]-a[i]>d)to[i]--;
        if(i!=to[i]){
            for(int k=i+1;k<to[i];k++)dis[i][k]=1;
            for(int k=to[i];k<=n;k++)if(~dis[to[i]][k])dis[i][k]=dis[to[i]][k]+1;
        }
    }
    for(int i=1;i<=n;i++)cout<<to[i]<<' ';cout<<'\n';
    cout<<'\n';
    for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<dis[i][j]<<' ';cout<<'\n';}
    cout<<'\n';
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
g++ migrate.cpp -o migrate -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ migrate.cpp -o migrate -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ migrate.cpp -o migrate -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ migrate.cpp -o migrate -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/