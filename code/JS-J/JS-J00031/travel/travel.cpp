#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<0<<0<<0<<0;
        return 0;
    }
    else
    {
        int a=(s1[0]-48)*10+(s1[1]-48),b=(s2[0]-48)*10+(s2[1]-48);
        if(a!=b)
        {
            cout<<1000;
            return 0;
        }
        else
        {
            a=s1[2]-'A',b=s2[2]-'A';
            if((a<=2&&b>2)||(a>2&&b<=2))
            {
                cout<<1100;
                return 0;
            }
            else
            {
                if(a==4)
                    a--;
                if(b==4)
                    b--;
                if(a-b==1||b-a==1)
                {
                    cout<<1111;
                    return 0;
                }
                else
                {
                    cout<<1110;
                    return 0;
                }
            }
        }
    }
}
