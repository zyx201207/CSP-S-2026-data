#include <bits/stdc++.h>
using namespace std;
string s,se,t,te;
int main(){
    freopen("in.travel","r",stdin);
    freopen("out.travel","w",stdout);
    cin>>s>>se>>t>>te;
    if(s==t)cout<<1;
    else cout<<0;
    if(se[0]==te[0]&&se[1]=te[1])cout<<1;
    else cout<<0;
    if(se[2]<=66&&te[2]<=66)cout<<1;
    else if(se[2]>=67&&te[2]>=67)cout<<1;
    else cout<<0;
    if(se[2]-te[2]==1||se[2]-te[2]==-1)cout<<1;
    else cout<<0;
    return 0;
}
