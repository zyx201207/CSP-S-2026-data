#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll k,t,l,sum,last;

string s,c1,c2,s1,s2;

int main( )
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    getline(cin,s);
    s = s + " ";
    l = s.size( );

    while(t != 4)
    {
        if(s[last + k] == ' ')
        {
            if(t == 0)
                c1 = s.substr(last,k);
            if(t == 1)
                s1 = s.substr(last,k);
            if(t == 2)
                c2 = s.substr(last,k);
            if(t == 3)
                s2 = s.substr(last,k);
            t ++;
            last = last + k + 1;
            k = 0;
        }
        else
            k ++;
    }

    if(c1 == c2)
    {
        cout<<"1";
        if(s1.substr(0,2) == s2.substr(0,2))
        {
            cout<<"1";
            if(('A' <= s1[2] && s1[2] <= 'C' && 'A' <= s2[2] && s2[2] <= 'C') || ('D' <= s1[2] && s1[2] <= 'F' && 'D' <= s2[2] && s2[2] <= 'F'))
            {
                cout<<"1";
                if((int(s1[2] + 1) == int(s2[2]) && s1[2] != 'C') || (int(s1[2]) == int(s2[2] + 1) && s2[2] != 'C'))
                    cout<<"1";
                else
                    cout<<"0";
            }
            else
                cout<<"00";
        }
        else
            cout<<"000";
    }
    else
        cout<<"0000";

    return 0;
}
