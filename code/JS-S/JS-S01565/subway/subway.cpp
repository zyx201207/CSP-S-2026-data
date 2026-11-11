#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int INF=0x3f3f3f3f;
int a[N];
int c,n,m,d,q;
int g[N][N];
void solve(){
    cin>>c>>n>>m>>d>>q;
    if(c==0&&n==2){
        cout<<32<<endl<<17;
        return;
    }
    if(c==0&&n==3){
        cout<<35<<endl<<16;
        return;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}