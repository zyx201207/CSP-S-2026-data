#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    long long l1,l2;
    if(c1==c2)
    {
        if(s1[0]==s2[0] and s1[1]==s2[1])
        {
            if(s1[2]<='c' and s1[2]>='a')
            {
                l1=1;
            }
            else
            {
                l1=2;
            }
            if(s2[2]<='c' and s2[2]>='a')
            {
                l2=1;
            }
            else
            {
                l2=2;
            }
            if(l2==l1)
            {
                if(s2[2]+1==s1[2] or s2[2]-1==s1[2])
                {
                    cout<<"1111";
                }
                else
                {
                    cout<<"1110";
                }
            }
            else
            {
                cout<<"1100";
            }
        }
        else
        {
            cout<<"1000";
        }

    }
    else
    {
        cout<<"0000"<<endl;
    }
    return 0;
}































































































































