#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    while(t--){
        cin>>c>>t>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c==11||c==12){
            if(3*(a[2]-a[1])<=d && n>=4){
                cout<<n-3<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            if(n>=4){
                cout<<n-4<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
    }
    return 0;
}

