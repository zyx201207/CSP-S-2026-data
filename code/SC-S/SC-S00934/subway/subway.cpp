#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int w[maxn],k[maxn],a[maxn][maxn],t[maxn][maxn],x[maxn],y[maxn];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=1;i<=q;i++){
        int ans=w[x[i]]+w[y[i]];
        int l=x[i],r=x[i];
        bool ir=true;
        while(r<=y[i]){
            ans+=t[l][r];
            if(ir){
                r++;
            }else{
                l++;
            }
            if(r==y[i]){
                break;
            }
        }
        cout<<ans+7<<" ";
    }
    return 0;
}