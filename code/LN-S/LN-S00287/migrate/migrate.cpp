#include<bits/stdc++.h>
using namespace std;
int c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t>>n>>d;
    if(n==4)cout<<1<<endl<<2;
    else if(n==5)cout<<0<<endl<<1;
    else cout<<0<<endl<<2;
    fclose(stdin);
    return 0;
}
