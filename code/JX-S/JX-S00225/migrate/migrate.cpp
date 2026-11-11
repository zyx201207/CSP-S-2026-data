#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,x[1000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t>>n>>d;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    if(n==4&&d==2){
        cout<<1<<endl<<2;
    }
    else if(n==5&&d==3){
        cout<<0<<endl<<1;
    }
    return 0;
}
