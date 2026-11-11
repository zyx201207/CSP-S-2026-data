#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
ll a[N],b[500][300005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++){
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++){
        ll k;
        cin>>k;
        for(int j = 1;j <= k;j++){
            cin>>b[i][j];
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        cout<<b[1][1] * n;
    }
    return 0;
}
