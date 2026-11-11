#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int sit1=0,sit2=0;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<'1';
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    sit1=(s1[0]-'0')*10+s1[1]-'0';
    sit2=(s2[0]-'0')*10+s2[1]-'0';
    if(sit1==sit2)
    {
        cout<<'1';
    }
    else
    {
        cout<<"000";
        return 0;
    }
    switch(s1[2])
    {
        case 'A':
            if(s2[2]=='B')
            {
                cout<<"11";
                break;
            }
            else if(s2[2]=='C')
            {
                cout<<"10";
                break;
            }
            else
            {
                cout<<"00";
                break;
            }
        case 'B':
            if(s2[2]=='A'||s2[2]=='C')
            {
                cout<<"11";
                break;
            }
            else
            {
                cout<<"00";
                break;
            }
        case 'C':
            if(s2[2]=='B')
            {
                cout<<"11";
                break;
            }
            else if(s2[2]=='A')
            {
                cout<<"10";
                break;
            }
            else
            {
                cout<<"00";
                break;
            }
        case 'D':
            if(s2[2]=='F')
            {
                cout<<"11";
                break;
            }
            else
            {
                cout<<"00";
                break;
            }
        case 'F':
            if(s2[2]=='D')
            {
                cout<<"11";
                break;
            }
            else
            {
                cout<<"00";
                break;
            }
    }
    return 0;
}
