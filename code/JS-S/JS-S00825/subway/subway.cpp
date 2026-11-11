#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=505;
long long w[N],t[N][N];
bool metro[N][N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q,k,zs;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            cin>>zs;
            metro[i][zs]=true;
            cin>>t[i][zs];
        }
    }
    long long x,y,ans=1e9;
    while(q--){
        cin>>x>>y;
        for(int i=1;i<=n;i++){
            if(metro[i][x]==true&&metro[i][y]==true){
                ans=min(ans,w[x]+w[y]+t[i][x]+t[i][y]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j&&(metro[i][x]&&metro[j][y])){
                    for(int p=1;p<=m;p++){
                        if(metro[i][p]&&metro[j][p]){
                            ans=min(ans,w[i]+t[i][x]+t[j][p]+t[i][p]+t[j][y]+w[y]);
                        }
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
