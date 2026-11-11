#include <bits/stdc++.h>
using namespace std;
string s1,s2;
char a1,a2,a3,b1,b2,b3;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>a1>>a2>>a3>>s2>>b1>>b2>>b3;
    if(s1==s2)
    {
        cout<<1;
        if(a1==b1&&a2==b2)
        {
            cout<<1;
            if(a3=='A')
            {
                if(b3=='B') cout<<"11";
                else if(b3=='C') cout<<"10";
                else cout<<"00";
            }
            if(a3=='B')
            {
                if(b3=='A') cout<<"11";
                else if(b3=='C') cout<<"11";
                else cout<<"00";
            }
            if(a3=='C')
            {
                if(b3=='B') cout<<"11";
                else if(b3=='A') cout<<"10";
                else cout<<"00";
            }
            if(a3=='D')
            {
                if(b3=='F') cout<<"11";
                else cout<<"00";
            }
            if(a3=='F')
            {
                if(b3=='D') cout<<"11";
                else cout<<"00";
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
