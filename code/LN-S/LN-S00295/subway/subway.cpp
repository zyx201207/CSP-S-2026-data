#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int a,t;cin>>a>>t;
        }
        while(q--){
            int x,y;cin>>x>>y;
            cout<<w[x]+w[y]<<endl;
        }
    }
    return 0;
}
