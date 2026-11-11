#include <bits/stdc++.h>

using namespace std;
long long c,t,n,d,x[1000005],cnt=0;
int main()
{
      freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
   cin>>c>>t;
   while(t--){
        cnt=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    if(d<x[2]-x[1]){
        cout<<0;
        return 0;
    }
        if(d>3*x[2]-3*x[1]){
            cout<<0;
            return 0;
        }
        long long l=1;
         long long r=l+3;
        while(r<=n){
          r=l+3;
            if(r<=n)
                cnt++;
                l++;
        }
        cout<<cnt<<endl;
   }
    return 0;
}
