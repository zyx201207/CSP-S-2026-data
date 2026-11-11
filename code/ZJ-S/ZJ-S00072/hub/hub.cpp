#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N=1e5+5;
int n,k,f[N],dis[N];
vector<int>e[N];
void _main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)e[i].clear();
    for(int i=1,x,y;i<n;i++)cin>>x>>y,e[x-1].push_back(y-1),e[y-1].push_back(x-1);
    int ans=n;
    for(int i=0;i<1<<n;i++)if(__builtin_popcount(i)==k){
        int s=0;
        for(int j=0;j<n;j++)if(i>>j&1){
            s++;
            for(int x:e[j])if(x>j&&(i>>x&1))s--;
        }
        if(s<=2){
            for(int j=0;j<n;j++)dis[j]=1e9;
            queue<int>q;
            for(int j=0;j<n;j++)if(i>>j&1)q.push(j),dis[j]=0;
            int mx=0;
            while(!q.empty()){
                int x=q.front();q.pop();
                mx=max(mx,dis[x]);
                for(int y:e[x])if(dis[y]>dis[x])dis[y]=dis[x]+1,q.push(y);
            }
            ans=min(ans,mx);
        }
    }
    cout<<ans<<'\n';
}
signed main(){
    clock_t _st=clock();
#ifndef LOCAL
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
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
g++ hub.cpp -o hub -O2 -std=c++14 -DLOCAL -Wall -Wextra
g++ hub.cpp -o hub -std=c++14 -DLOCAL -fsanitize=address,undefined -Wall -Wextra
g++ hub.cpp -o hub -std=c++14 -DLOCAL -fsanitize=address,undefined -pg -Wall -Wextra
g++ hub.cpp -o hub -std=c++14 -DLOCAL -fsanitize=address,undefined -g -Wall -Wextra
*/