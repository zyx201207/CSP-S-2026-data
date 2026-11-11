#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>d;
        int x,y;cin>>x>>y;
        if(d>=2*(y-x)){
            cout<<n-2<<"\n";
        }
    }
}
