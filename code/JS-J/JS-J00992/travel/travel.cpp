#include<bits/stdc++.h>
const double PI = 3.14159;
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;//A is 65
    cin>>c1>>s1>>c2>>s2;
    if(c1[1]!=c2[1]||c1[0]!=c2[0])
    {
        cout<<"0000";
        return 0;
    }
    else if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"1000";
        return 0;
    }
    int a=s1[2],b=s2[2];
    if(a>=68&&a<=70)
    {
        if(b>=68&&b<=70)
        {
            cout<<"1111";
            return 0;
        }
        else
        {
            cout<<"1100";
            return 0;
        }
    }
    else{
        if(b>=68&&b<=70)
        {
            cout<<"1100";
            return 0;
        }
        else{
            if(abs(a-b)==1)
            {
                cout<<"1111";
                return 0;
            }
            else cout<<"1110";
        }
    }
    return 0;
}
