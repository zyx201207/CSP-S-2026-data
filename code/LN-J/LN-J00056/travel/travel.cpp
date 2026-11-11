#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c11,s11,c22,s22;
    cin>>c11>>s11>>c22>>s22;
    if(c11[0]==c22[0] && s11[0]==s22[0])
    {
        cout<<'1';
        if(s11[0]==s22[0] || s11[1]==s22[1])
        {
            cout<<'1';
            if((s11[2]=='D' || s11[2]=='F') && (s22[2]=='D' || s22[2]=='F')) || ((s11[2]=='A' || s11[2]=='B' || s11[2]=='C') && (s22[2]=='A' || s22[2]=='B' || s22[2]=='C')))
            {
                cout<<'1';
                if((s11[2]=='A' && s22[2]=='B') || (s11[2]=='B' && s22[2]=='C') || (s11[2]=='D' && s22[2]=='F'))
                {
                    cout<<'1';
                }
                else
                {
                    cout<<'0';
                }
            }
            else
            {
                cout<<'00';
            }
        }
        else
        {
            cout<<'000';
        }
    }
    else
    {
        cout<<'0000';
    }
    return 0;
}
