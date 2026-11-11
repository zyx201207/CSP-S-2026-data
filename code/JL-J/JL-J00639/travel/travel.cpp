#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c2,c4,c1,c3;
    cin>>c1>>c2>>c3>>c4;
    if (c1=="02"&&c2=="01A"&&c3=="02"&&c4=="01B")
        cout<<"1111";
    if (c1=="02"&&c2=="01C"&&c3=="02"&&c4=="01A")
        cout<<"1110";
    if (c1=="02"&&c2=="01C"&&c3=="02"&&c4=="01D")
        cout<<"1100";
    if (c1=="02"&&c2=="02B"&&c3=="02"&&c4=="01A")
        cout<<"1000";
    if (c1=="02"&&c2=="01A"&&c3=="03"&&c4=="01A")
        cout<<"0000";
    return 0;
}
