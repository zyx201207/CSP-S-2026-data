#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string p1,p2;
string l1,l2,pd="";
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    p1=s1.substr(0,2);
    p2=s2.substr(0,2);
    l1=s1[2];
    l2=s2[2];
    pd=l1+l2;
    if(p1!=p2)
    {
        cout<<"1000"<<endl;
        return 0;
    }
    if(pd=="AD"||pd=="AF"||pd=="BD"||pd=="BF"||pd=="CD"||pd=="CF")
    {
        cout<<"1100"<<endl;
        return 0;
    }
    if(pd=="DA"||pd=="FA"||pd=="DB"||pd=="FB"||pd=="DC"||pd=="FC")
    {
        cout<<"1100"<<endl;
        return 0;
    }
    if(pd=="AB"||pd=="BA")
        cout<<"1111"<<endl;
    else if(pd=="BC"||pd=="CB")
        cout<<"1111"<<endl;
    else if(pd=="DF"||pd=="FD")
        cout<<"1111"<<endl;
    else cout<<"1110"<<endl;
    return 0;
}
// AD AF
// BD BF
// CD CF
