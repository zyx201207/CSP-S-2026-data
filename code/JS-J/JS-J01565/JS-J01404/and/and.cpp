#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001][31],ij[200001][32],cntt[32];
long long ans,x[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long t;
        int cnt=0;
        cin>>x[i];
        t=x[i];
        while(t!=0){
            a[i][cnt]=t%2;
            t=t>>1;
            cnt++;
        }
    }
    cntt[31]=n;
    for(int i=1;i<=n;i++)ij[i][31]=i;
    for(int i=30;i>=0;i--){
        for(int j=1;j<=cntt[i+1];j++){
            if(a[ij[j][i+1]][i]==1){
                cntt[i]++;
                ij[cntt[i]][i]=ij[j][i+1];
            }
        }
        if(cntt[i]<m){
            cntt[i]=cntt[i+1];
            for(int j=1;j<=cntt[i+1];j++){
                ij[j][i]=ij[j][i+1];
            }
        }
    }
    ans=x[ij[1][0]];
    for(int i=2;i<=m;i++){
        ans=ans&x[ij[i][0]];
    }
    cout<<ans<<"\n";
    return 0;
}
