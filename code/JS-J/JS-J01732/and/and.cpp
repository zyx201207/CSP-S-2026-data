#include<bits/stdc++.h>
using namespace std;
long long a[2005];
long long c[2005][2005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m;i++){
        c[0][i]=a[1];
    }
    for(int i=1;i<=n;i++){
        c[i][0]=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            c[i][j]=max(c[i-1][j],c[i-1][j-1]^a[i]);
        }
    }
    long long ans=0;
    for(int i=m;i<=n;i++){
        ans=max(c[i][m],ans);
    }
    cout<<ans<<endl;
    return 0;
}