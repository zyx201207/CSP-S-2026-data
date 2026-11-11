#include<bits/stdc++.h>
using namespace std;
int w[50005],k[50005],a[505][505],t[505][505];
int x[50005],y[50005];
vector<int> q[1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    long long sum=0;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }

    for(int i=1;i<=n;i++){
       cin>>k[i];
       for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
       }
       //for(int j=1;j<=k;j++){
            //if(i<n){

            //}
      // }
    }
    for(int i=1;i<=q;i++){
        long long sum=0;
        cin>>x[i]>>y[i];
        sum+=w[x[i]]+w[y[i]];
    }
    cout<<sum;
}
