#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1, s1;
    string c2,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1 == s1)
    {
        cout << "11";
    }
    else
    {
        cout<< "00";
    }
    if(c2[1] == s2[1])
    {
        cout << "1";

    }
    else{
        cout << "0";
    }
    if(c2[2] == s2[2])
    {
        cout << "1";

    }
    else{
        cout << "0";
    }

    return 0;
}
