#include<bits/stdc++.h>
using namespace std;
int sot(string a)
{
    if(a[2] == 'A')
    {
        return 1;
    }
    if(a[2] == 'B')
    {
        return 2;
    }
    if(a[2] == 'C')
    {
        return 3;
    }
    if(a[2] == 'D')
    {
        return 4;
    }
    if(a[2] == 'F')
    {
        return 5;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1 == c2)
    {
        cout<<1;
        if(s1[0]+s1[1] == s2[0]+s2[1])
        {
            cout<<1;
            if(sot(s1) == 1||sot(s1) == 2||sot(s1) == 3)
            {
                if(sot(s2) <= 3)
                {
                    cout<<1;
                    if(sot(s1) - sot(s2) == 1||sot(s1) - sot(s2) == -1)
                    {

                        cout<<1;
                        return 0;
                    }
                    else
                    {

                        cout<<0;
                        return 0;
                    }
                }
                else
                {

                    cout<<"00";
                    return 0;
                }
            }
            if(sot(s1) == 4||sot(s1) == 5)
            {
                if(sot(s2) >3||sot(s2) <= 5)
                {

                    cout<<11;
                    return 0;
                }
                else
                {

                    cout<<"00";
                    return 0;
                }
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }

    return 0;
}
