#include<bits/stdc++.h>
using namespace std;
long long a[500005],sum[500005],nmax;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        //cout<<sum[i]<<" ";
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(a[i]*(i-j)-sum[i-1]+sum[j-1]<=m){
                nmax=max(nmax,i-j+1ll);
            }
        }
    }
    cout<<nmax;
    return 0;
}
