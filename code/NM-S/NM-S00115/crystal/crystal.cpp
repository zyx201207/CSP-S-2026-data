#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int n;
long long m,ans=0;
long long a[MAXN],w[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    w[1]=0;
    for(int i=2;i<=n;i++) {
         w[i]=w[i-1]+(i-1)*(a[i]-a[i-1]);
         //cout<<w[i]<<" ";
    }
    //cout<<"\n";
    //cout<<"\n";
    int r=1;
    //cout<<a[n]-a[1]<<" ";
    //cout<<w[n]-w[1]<<" ";
    //cout<<m<<" ";
    for(int i=1;i<=n;i++){
        while(w[r]-w[i]-((i-1)*(a[r]-a[i]))<=m&&r<=n) r++;
        //cout<<r<<" ";
        r--;
        if(r>n) r--;
        //cout<<r<<"\n";
        if(ans<r-i+1) ans=r-i+1;
    }
    cout<<ans;
    return 0;
}
