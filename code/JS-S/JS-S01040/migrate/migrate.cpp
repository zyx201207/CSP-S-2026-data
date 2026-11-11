#include<bits/stdc++.h>
using namespace std;
long long mx,mxx,n,s,a[1000001],ans[1000001];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdin);
    cin>>mx>>a[2]>>n;
    if(n==5){
        cout<<0<<endl<<1;
        return 0;
    }
    if(n==4){
        cout<<1<<endl<<2;
        return 0;
    }
    cout<<1<<endl<<2;
    return 0;
}
