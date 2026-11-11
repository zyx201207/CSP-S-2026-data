#include<bits/stdc++.h>
using namespace std;
int a[10000005],f[1000005];
int main(){
    freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    long long cnt=0,n,d;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
                cin>>a[i];
        }
        f[1]=0,f[2]=0,f[3]=0,f[4]=1,f[5]=2;
        for(int i=6;i<=n;i++){
            f[n]=f[n-1]+f[n-2];
        }
        cout<<f[n]<<'\n';
    }
    return 0;
}
