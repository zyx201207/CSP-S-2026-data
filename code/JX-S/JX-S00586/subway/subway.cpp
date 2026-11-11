#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,x,y,ans;
ll w[500005],k[505];
struct node{
    ll a,t;
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    node s[505][500005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>s[i][j].a>>s[i][j].t;
        }
    }
    while(q--){
        cin>>x>>y;
        ans=w[x]+w[y];
        for(int i=1;i<=n;i++){
            if(i==x){
                for(int j=1;j<=k[i];j++){
                    if(s[i][j].a==y){
                        ans+=s[i][j].t;
                        cout<<ans;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
