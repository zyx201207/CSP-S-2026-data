#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if((x[2]-x[1])*2<=d){
            cout<<n-3<<endl;
        }
    }
    return 0;
}
