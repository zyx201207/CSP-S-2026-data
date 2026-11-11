#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        int p1=(s1[0]-'0')*10+(s1[1]-'0'),p2=(s2[0]-'0')*10+(s2[1]-'0');
        if(p1==p2)
        {
            cout<<1;
            int h1=s1[2]-'A',h2=s2[2]-'A';
            if((h1<=2&&h2<=2)||(h1>2&&h2>2))
            {
               cout<<1;
               if(abs(h1-h2)==1) cout<<1;
               else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
