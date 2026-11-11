//JS-S01333
//remember to reset handin and debug
#include<bits/stdc++.h>
#define handin 0
#define debug 1
using namespace std;
int c,n,m,d,q;
int w[500010],a[510][510],t[510][510];
int sum[500010];
signed main(){
    #if handin
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    #endif // handin
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
        sum[i]=sum[i-1]+w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
    //        sum[i]=sum[i-1]+t[i][j];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<"\n";
    }
    return 0;
}

