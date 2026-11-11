#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    bool one=false;
    if (c1==c2)
    {
        one=true;
    }
    bool two=false;
    if (one&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        two=true;
    }
    bool three=false;
    int q=s1[2]-'A',w=s2[2]-'A';
    if(one&&two)
    {
        bool x=false,z=false;
        for (int i=0;i<3;i++)
        {
            if(q==i)
            {
                x=true;
            }
            if(w==i)
            {
                z=true;
            }
        }
        if(z&&x)
        {
            three=true;
        }
        if(!three)
        {
            bool x2=false,z2=false;
            for (int j=0;j<2;j++)
            {
                if(q==j)x2=true;
                if(w==j)z2=true;
            }
            if(z2&&x2)
            {
                three=true;
            }
        }
    }
    bool four=false;
    if (one&&two&&three&&abs(q-w)==1)
    {
        four=true;
    }
    cout<<one<<two<<three<<four;
    return 0;
}
