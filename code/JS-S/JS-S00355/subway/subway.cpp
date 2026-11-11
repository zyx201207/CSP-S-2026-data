#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7,M=5e2+7;
int w[N],k[M];
int a[M][N],t[M][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;++i){
        cin>>w[i];
    }
    for(int i=1;i<=n;++i){
        cin>>k[i];
        for(int j=1;j<=k[i];++j){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int r=1;r<=q;++r){
        int ans=0,x,y;
        cin>>x>>y;
        ans=w[x]+w[y];
        ans=ans+x+y;
        cout<<ans<<"\n";
    }
    return 0;
}
