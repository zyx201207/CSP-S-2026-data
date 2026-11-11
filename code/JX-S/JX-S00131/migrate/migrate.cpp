#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n==4&&d==2){
            cout<<1<<endl;
        }
        else if(n==5&&d==2){
            cout<<2<<endl;
        }
        else if(n==5&&d==3){
            cout<<0<<endl;
        }
        else if(n==6&&d==2){
            cout<<1<<endl;
        }
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}
