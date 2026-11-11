#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510,M=5e5+10;
int w[M],k[N],a[N][N],t[N][N];

signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        int x,y,ans=0;
        cin>>x>>y;
        ans+=w[x]+w[y];
        int h=1,l=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k[i];j++){
                if(a[i][j]==x){
                    ans+=t[i][j];
                    h=i;
                    l=j;
                    break;
                }
            }
        }
        while(a[h][l]!=y){
            int f=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k[i];j++){
                    if(a[i][j]==a[h][l]&&i!=h&&l!=j){
                        ans+=t[i][j];
                        h=i;
                        l=j;
                        f=1;
                        break;
                    }
                }
                if(f==1) break;
            }
            l++;
            ans+=t[h][l];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
