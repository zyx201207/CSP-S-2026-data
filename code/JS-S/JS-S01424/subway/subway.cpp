#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y;
    int w[500001],k[501][1000002],ans[100001];
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i][0];
        for(int j=1;j<=2*k[i][0];j++){
            cin>>k[i][j];
        }
    }
    for(int i=0;i<q;i++){
        cin>>x>>y;
        ans[i]=k[0][1+2*x]+k[i][1+2*y];
    }
    for(int i=0;i<q;i++){
        cout<<ans[i]<<'\n';
    }
    return 0;
}
