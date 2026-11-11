#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    for(int i=0;i<=t;t++){
       int n,d;
       cin>>n>>d;
       for(int j=1;j<=n;j++){
            cin>>x[i];
       }
       for(int j=0;j<t;j++){
            cout<<j<<endl;
       }
    }
    fclose(stdin);
    fclose(stdout);
}

