#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll c,n,m,d,q,w[N],a,b;
ll ans;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    cin>>a>>b;
    ans+=w[1]+w[m]+a+b;
    cout<<ans;
    return 0;
}
