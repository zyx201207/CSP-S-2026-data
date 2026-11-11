#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,c,t,d,sum=0;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        cout<<x[1]<<endl;
    }
    return 0;
}
