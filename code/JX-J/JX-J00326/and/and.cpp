#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10,M=2e5+10;
int n,m,a[M],f[N][N],s[M],ans,ss[M];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i][1]=a[i];
        s[i]=1;
    }if(m==n-1){
        for(int i=1;i<=2;i++){
            ss[i]=a[i];
            for(int j=i+1;j<=m+i-1;j++){
                ss[j]=ss[j-1]&a[i];
            }ans=max(ans,ss[m+i-1]);
        }cout<<ans<<"\n";
        return 0;
    }if(m==n){
        ss[1]=a[1];
        for(int i=2;i<=n;i++) ss[i]=ss[i-1]&a[i];
        cout<<ss[n]<<"\n";
        return 0;
    }for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            for(int k=1;k<=m;k++){
                f[i][k]=max(f[i][k],f[j][k-1]&a[i]);
            }ans=max(f[i][m],ans);
        }
    }cout<<ans<<"\n";
    return 0;
}