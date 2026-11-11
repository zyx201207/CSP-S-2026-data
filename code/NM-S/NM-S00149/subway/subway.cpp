#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c=0,n=0,m=0,d=0,q=0,ans=0;
    cin>>c>>n>>m>>d>>q;
    int w[m+1]={0};
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }int k[n+1]={0},a[m+1][m+1]={0},t[m+1][m+1]={0};
    int ar[n+1][m+1]={0};
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            ar[i][a[i][j]]=t[i][j];
        }
    }int x[q+1]={0},y[q+1]={0};
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
        ans=w[x[i]]+w[y[i]];
        for(int j=1;j<=n;j++){
            if(ar[j][x[i]])ans+=ar[j][x[i]];
            if(ar[j][y[i]])ans+=ar[j][y[i]];
        }
    }
    cout<<ans;
    return 0;
}
