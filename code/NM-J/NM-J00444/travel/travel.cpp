#include<iostream>
using namespace std;
int main()
{
    freopen("travel.in","r",instd);
    freopen("travel.out","w",outstd);
    string c1,c2,s1,s2;
    string a="1100";
    cin>>c1;
    cin>>s1;
    cin>>c2;
    cin>>s2;
    if(c1!=c2)
        a="0000";
    else if(s1==s2)
        a="1111";
    cout<<a;
    return 0;
}
