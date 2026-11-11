#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,a1,a2;
    cin>>c1>>s1>>c2>>s2;
    a1.push_back(s1.back());s1.pop_back();
    a2.push_back(s2.back());s2.pop_back();
    if(a1>a2)swap(a1,a2);
    if(c1==c2)cout<<1;
    else{cout<<"0000";return 0;}
    if(s1==s2)cout<<1;
    else{cout<<"000";return 0;}
    if((a1=="A" && a2=="B") || (a1=="B" && a2=="C") || (a1=="D" && a2=="F"))cout<<"11";
    else if(a1=="A" && a2=="C")cout<<"10";
    else cout<<"00";
    return 0;
}
