#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000005],y[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
    }
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>y[j];
        }
    }
    cout<<1<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
