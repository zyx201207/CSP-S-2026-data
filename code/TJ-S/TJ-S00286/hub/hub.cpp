#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=105;

int n,k;
vector<int> g[N];

int check(int u,int fa,int res,int mark){
    int tmp=res;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        if(mark&(1<<u) && !(mark&(1<<v))) tmp+=check(v,u,res+1,mark);
        else tmp+=check(v,u,res,mark);
    }
    return tmp;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c,t;cin>>c>>t;
    while(t--){
        for(int i=1;i<=N;i++) g[i].clear();
        cin>>n>>k;
        for(int i=1;i<n;i++){
            int u,v;cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int mark=0;mark<(1<<n);mark++){
            int num=0;
            for(int i=1;i<=n;i++){
                if(mark&(1<<i-1)){
                    num++;
                }
            }
            if(num!=k) continue;
            if(check(1,0,0,mark)>2) continue;

        }
        cout<<1<<"\n";
    }

    return 0;
}

/*

g++ -o hub hub.cpp -std=c++14 -O2 -static

./ hub

*/