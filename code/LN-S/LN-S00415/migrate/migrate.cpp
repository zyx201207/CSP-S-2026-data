#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c>=15&&c<=18){
        while(t--){
            int n;
            cin>>n;
            cout<<n*(n-1)/2<<endl;
        }
    }
    return 0;
}
