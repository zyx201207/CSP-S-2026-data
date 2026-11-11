#include<bits/stdc++.h>
#define int long long
#define N 200007 
using namespace std;
int n,ans=1,m,mx;
int a[N];
bool c[N][37]={0};
int b[37];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    sort(a+1,a+n+1);
    ans=a[n-m+1];
    if(m==1) ans=mx;
    //for(int i=1;i<=n;i++){
   //     cout<<a[i]<<endl;
  //  }
    cout<<ans<<endl;
    return 0;  
}