#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10;
typedef long long ll;
ll a[M];
ll a1[505][M];
ll x1[M],y1[M];
int main(){
   freopen("subway.in","r",stdin);
   freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;
        for(int j=1;j<=k;j++)
            cin>>a1[i][j]>>a2[i][j];
    }
    for(int i=1;i<=q;i++){
        cin>>x1[i]>>y1[i];
    }
    cout<<c<<endl<<n<<endl<<m<<endl<<d<<endl<<q<<endl;
    return 0;
}
