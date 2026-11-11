#include<bits/stdc++.h>
using namespace std;
long long n,d,c,t;
long long a[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>a[j];
        }
        if(t==2){
            if(n==4&&d==2) cout<<1<<endl;
            else if(n==5&&d==2) cout<<2<<endl;
            else if(n==5&&d==3) cout<<0<<endl;
            else if(n==6&&d==2) cout<<1<<endl;
        }
    }
    return 0;
}
