#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,mi=1000000000,z;
    for(int i=0;i<=n;i++){
        cin>>z;
        if(mi>z)mi=z;
    }
    cout<<mi;
    return 0;
}
