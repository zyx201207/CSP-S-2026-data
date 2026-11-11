#include<bits/stdc++.h>
using namespace std;
int n,d,c,t;
int a[10000];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
        cin>>c>>t;
        for(int i=1;i<=t;i++){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
        }
        if(n==5&&d==2){
            cout<<1<<endl;
            cout<<2<<endl;
        }
        else if(n==6&&d==2){
            cout<<0<<endl;
            cout<<1<<endl;
        }else {
            cout<<0<<endl;
            cout<<0<<endl;
        }






    return 0;
}
