#include<bits/stdc++.h>
using namespace std;
int w[1000001],k[1000001],a[1001][1001],t[1001][1001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    if(c==0||c==7||c==8||c==9||c==10||c==11||c==12||c==13||c==14||c==15||c==16||c==17||c==18||c==19){
        for(int i=1;i<=m;i++){
            cin>>w[i];
        }
        for(int i=1;i<=n;i++){
            cin>>k[i];
            for(int j=1;j<=k[i];j++){
                cin>>a[i][j]>>t[i][j];
            }
        }
        while(q--){
            int x,y;
            cin>>x>>y;
            long long ans=0;
            ans+=w[x]+w[y];
            ans+=abs(y-x)*t[1][1];
            cout<<ans<<"\n";
        }
    }
    return 0;
}