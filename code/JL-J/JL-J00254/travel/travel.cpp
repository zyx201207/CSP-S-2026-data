#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen ("travel.in","r",stdin);
    freopen ("travel.out","w",stdout);
    int c1,c2;
    char s1,s2,d1,d2,d3,d4;
    cin>>c1>>s1>>c2>>s2;
    d1=(s1/100)*10+s1/10%10;
    d2=s1%10;
    d3=(s2/100)*10+s2/10%10;
    d4=s2%10;
    if(c1!=c2&&s1!=s2)
     {
         cout<<"0000";
         return 0;
     }
    if(d1!=d3)
        {
            cout<<"1000";
            return 0;
        }

    if(((d2=='A'||d2=='B'||d2=='C')&&(d4=='D'||d4=='F'))||((d2=='D'||d2=='F')&&(d4=='A'||d4=='B'||d4=='C')))
        {
            cout<<"1100";
            return 0;
        }
    if((d2=='A'&&d4=='C')||(d2=='C'&&d4=='A'))
        {
            cout<<"1110";
            return 0;
        }
    else
        cout<<"1111";
    return 0;
}
