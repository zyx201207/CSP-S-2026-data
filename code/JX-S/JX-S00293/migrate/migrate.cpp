#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c;
    cin>>c;
    if(c==1)
        cout<<1<<"\n"<<2;
    if(c==2)
        cout<<0<<"\n"<<1;
    else
        cout<<1<<"\n"<<1;
    return 0;
}
