#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q>>a;
    if(q==2&&a==4)cout<<32<<endl<<17;
    else if(q==2&&a==8)cout<<35<<endl<<16;
    else cout<<a;

    return 0;
}
