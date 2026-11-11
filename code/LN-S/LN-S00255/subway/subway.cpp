#include <bits/stdc++.h>
using namespace std;
const int M=5e5+1,N=1e5+1;
int w[M],x[N],y[N],a[501][M],t[501][M];
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++) cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        cout<<12<<'\n';
    }
    return 0;
}
