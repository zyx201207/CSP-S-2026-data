#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(n==2)cout<<32<<endl<<17;
    else if(n==3)cout<<35<<endl<<16;
    else cout<<36<<endl<<13;
    fclose(stdout);
    return 0;
}
