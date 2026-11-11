#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
        int c,t;
    cin>>c>>t;
   while(t--){
    int n,d;
    cin>>n>>d;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<(a[n-1]-a[0])/d<<endl;
   }
}
