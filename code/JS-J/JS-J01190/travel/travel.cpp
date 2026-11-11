#include <iostream>
using namespace std;
string c1,c2,s1,s2;
inline bool check0(){return c1==c2&&s1.substr(0,2)==s2.substr(0,2);}
inline bool check1(){return s1[2]<='C'?s2[2]<='C':s2[2]>'C';}
inline bool check2(){return check1()&&(abs(s1[2]-s2[2])==1);}
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2)<<check0()<<(check0()&&check1())<<(check0()&&check2())<<'\n';
    return 0;
}
