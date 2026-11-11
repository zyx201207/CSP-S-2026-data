#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll c,n,m,d,q,k,x,y,ans=0;
ll w[500005];
ll sum[1000][1000];
struct node{
    ll a,t;

}s[505][3];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>s[i][j].a>>s[i][j].t;
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        ans=0;
        ans+=w[x];
        ans+=w[y];

    }
    cout<<ans<<endl;
    fclose(stdout);
    return 0;
}

