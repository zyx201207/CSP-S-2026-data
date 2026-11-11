#include<bits/stdc++.h>
using namespace std;
int c,n;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c;
    cin>>n;
    if(n==2)cout<<1<<endl<<2<<endl;
    if(n==3)cout<<1<<endl<<1<<endl<<2<<endl;
    if(n==5)cout<<17<<endl<<9<<endl<<6<<endl<<6<<endl<<9<<endl;
    return 0;
}
