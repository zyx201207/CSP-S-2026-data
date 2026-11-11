#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[100000005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
   cin>>c>>t;
   while(t--){
    cin>>n>>d;
    if(n==1||n==2){
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
      cout<<0;
    }
   }
    return 0;

}
