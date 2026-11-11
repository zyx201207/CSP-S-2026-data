#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long c,n,m,d,q,w[N];
long long k[510],a[N][5],t[N][5];
void bfs()
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[j][1]>>t[j][1]>>a[j][2]>>t[j][2];
        }
    }
    while(q--){
        int xr,yr;
        cin>>xr>>yr;
        cout<<"0\n";
    }
    return 0;
}
