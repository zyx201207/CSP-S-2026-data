#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
int c,n,m,d,q;
int w[N],t[2010][2010],a[2010][2010],ans=0;
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        ans+=w[l]+w[r];
        for(int i=l;i<=r;i++){
            for(int j=l;j<=r;j++){
                ans+=t[i][j];
            }
        }
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
