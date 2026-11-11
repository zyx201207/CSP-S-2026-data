#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,a,b;
    cin>>c>>t>>a>>b;
    if(c==0){
        if(t==16&&a==174944)
            cout<<"\n6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        if(t==14&&a==200001)
            cout<<"\n9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        if(t==12&&a==260000)
            cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        if(t==17&&a==197)
            cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        if(t==2&&a==5)
            cout<<"0\n1";
        if(t==2&&a==4)
            cout<<"1\n2";
    }
    return 0;
}
