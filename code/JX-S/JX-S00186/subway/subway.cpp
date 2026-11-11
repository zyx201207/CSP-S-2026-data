#include <bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k,a[500][2005],t[500][2005],j,s;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    while(n--){
        cin>>k;
        for(int i=1;i<=k;i++){
            cin>>a[i][j]>>t[i][j];
            s+=t[i][j];
        }
        cout<<w[1]+s+w[m]<<"\n";
        s=0;
    }
    return 0;
}
