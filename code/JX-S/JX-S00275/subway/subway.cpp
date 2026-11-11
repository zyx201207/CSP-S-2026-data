#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
const int N=1e5+5,M=1e3+5;
int w[N],a[M][M],t[M][M],x[N],y[N],h[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;cin>>k;h[i]=k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=p;i++){
        cin>>x[i]>>y[i];
        int f,l,z[N],v=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=h[i];j++){
                if(a[i][j]==x[i]){
                    f=i;
                }
                
                if(a[i][j]==y[i]){
                    l=i;
                }
                if(a[i][j]==a[i+1][j]){
                    z[i]=i;
                    v++;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=v;i++){
            ans+=z[i];
        }
        ans+=(w[f]+t[1][f]+w[l]+t[n][l]);
        cout<<ans;
    }
    return 0;
}