#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,a[N],ans,b[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        for(int j=1;j<=k;j++)cin>>b[i][j];
    }
    for(int i=1;i<=d;i++){
        int x,y,ans;cin>>x>>y;
        ans=a[x]+a[y];
        cout<<ans+a[i]<<endl;
    }
    return 0;
}
