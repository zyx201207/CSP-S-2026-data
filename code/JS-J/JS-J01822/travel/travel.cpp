#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    cout<<s1;
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]-'0'+c1[1]-'0'!=c2[0]-'0'+c2[1]-'0')
    {
        cout<<"0000";
        return 0;
    }
    else
    {
        if(s1[0]-'0'+s1[1]-'0'!=s2[0]-'0'+s2[1]-'0')
        {
            cout<<"1000";
            return 0;
        }
        else
        {
            if(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))||((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='D'||s1[2]=='F')))
            {
                cout<<"1100";
                return 0;
            }
            else
            {
                if(s1[2]=='A'&&s2[2]!='B')
                {
                    cout<<"1110";
                    return 0;
                }
                if(s1[2]=='B'&&(s2[2]!='A'&&s2[2]!='C'))
                {
                    cout<<"1110";
                    return 0;
                }
                if(s1[2]=='C'&&s2[2]!='B')
                {
                    cout<<"1110";
                    return 0;
                }
                if(s1[2]=='D'&&s2[2]!='F')
                {
                    cout<<"1110";
                    return 0;
                }
                if(s1[2]=='F'&&s2[2]!='D')
                {
                    cout<<"1110";
                    return 0;
                }
            }
        }
    }
    cout<<"1111";
    return 0;
}
