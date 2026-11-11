#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=305;

int n;
ll d,pos[N],res[N],minn[N];

void dfs(ll x,ll step){
    if(step<=minn[x]){
        minn[x]=step;
        res[x]++;
    }
    if(x>=n) return;
    for(int i=x;i<=n;i++){
        if(pos[i]-pos[x]>d) break;
        dfs(i+1,step+1);
    }
}

void solve1(){
    if(pos[n]-pos[1]<=d){
        cout<<0<<"\n";
        return;
    }
    ll ans=0;
    for(int i=2;i<=n;i++){
        if(pos[i]-pos[1]<=d&&pos[n]-pos[i]<=d){
            ans+=i;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int c,t;cin>>c>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>pos[i];
        if(c==13||c==14) solve1();
        int ans=0;
        for(int i=1;i<=n;i++){
            memset(res,0,sizeof(res));
            memset(minn,0x3f,sizeof(minn));
            dfs(i,0);
            for(int j=1;j<=n;j++){
                if(res[j]==2){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }

    return 0;
}

/*

g++ -o migrate migrate.cpp -std=c++14 -O2 -static

./migrate <migrate1.in >migrate1.out

diff migrate1.out migrate1.ans

*/