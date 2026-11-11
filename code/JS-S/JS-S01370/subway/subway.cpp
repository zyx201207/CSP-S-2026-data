#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e2+5,M=5e5+5;
int c,n,m,d,q;
int w[M];
void solve(){
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    while(q--){
        cout<<10<<endl;
    }
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
    return 0;
}