#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
    if (a!=b){
        cout<<"0000";
        return 0;
    }
    if (c[0]!=d[0] || c[1]!=d[1]){
        cout<<"1000";
        return 0;
    }
    if ((c[2]=='D' || c[2]=='F')^(d[2]=='D' || d[2]=='F')){
        cout<<"1100";
        return 0;
    }
    if ((c[2]=='A' && d[2]=='C') || (c[2]=='C' && d[2]=='A')){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
