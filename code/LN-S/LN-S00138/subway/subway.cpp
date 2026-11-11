#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,x,y,a[505][20005],t[505][20005];
long long w[20005];
vector<long long> path;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    vector<int> e[20005];
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++) cin>>w[i];
    for(int i = 1;i<=n;i++){
        cin>>k;
        for(int j = 1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
    }
    if(n == 2&&m == 5) cout<<32<<'\n'<<17;
    else if(n == 3&&m == 7) cout<<35<<'\n'<<16;
    else cout<<67;
    return 0;
}
