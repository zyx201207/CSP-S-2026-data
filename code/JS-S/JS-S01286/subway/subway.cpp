#include<bits/stdc++.h>
using namespace std;
int w[500005];
vector<pair<int,int> > vt[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        for(int j=1;j<=x;j++){
            int a,t;
            cin>>a>>t;
            vt[i].emplace_back(a,t);
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        int ans=0;
        for(int j=min(x,y);j<=max(x,y);j++)
            ans+=w[i];
        cout<<ans<<'\n';
    }
    return 0;
}
