#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string s,v;
    cin>>n>>s>>m>>v;
    if(n==m)
    {
        cout<<'1';
        if(s[0]==v[0]&&s[1]==v[1])
        {
            cout<<'1';
            if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(v[2]=='A'||v[2]=='B'||v[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(v[2]=='D'||v[2]=='F')))
            {
                cout<<'1';
                if((s[2]=='A'&&v[2]=='B')||(v[2]=='A'&&s[2]=='B')||(s[2]=='B'&&v[2]=='C')||(v[2]=='B'&&s[2]=='C')||(s[2]=='D'&&v[2]=='F')||(v[2]=='D'&&s[2]=='F'))
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
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
