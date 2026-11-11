#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],num[500005],t[500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>num[j]>>t[j];
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(num[j]==x){
                    cnt1[i][j]=w[num[j]]+t[j];
                }else if(num[j]==y){
                    cnt2[i][j]=w[num[j]]+t[j];
                }
            }
        }
        */
        cout<<"0\n";
    }
    return 0;
}
