#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool b1,b2,b3,b4;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        b1=1;
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            b2=1;
            if((s1[2]!='C' && s2[2]!='D')&&
               (s1[2]!='D' && s2[2]!='C'))
            {
                b3=1;
                if(abs(int(s1[2]-s2[2]))==1) b4=1;
            }
        }
    }
    cout<<b1<<b2<<b3<<b4;
    return 0;
}
