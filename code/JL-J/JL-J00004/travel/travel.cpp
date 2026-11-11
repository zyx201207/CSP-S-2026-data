#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string co,so,ct,st;
    cin>>co>>so>>ct>>st;
    if(co==ct)cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    string ao=so.substr(0,2),an=so.substr(2,1);
    string bo=st.substr(0,2),bn=st.substr(2,1);
    if(ao==bo)cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    if((an<="C"&&bn<="C")||(an>="D"&&bn>="D"))cout<<1;
    else{
        cout<<"00";
        return 0;
    }
    if((an=="A"&&bn=="B")||(an=="B"&&bn=="A")||(an=="B"&&bn=="C")||(an=="C"&&bn=="B")||(an=="D"&&bn=="F")||(an=="F"&&bn=="D"))cout<<1;
    else cout<<0;
    return 0;
}
