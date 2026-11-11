#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool isce(string s3,string s4)
{
    if((s3[2]=='A'||s3[2]=='B'||s3[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')) return 1;
    else if((s3[2]=='E'||s3[2]=='D')&&(s4[2]=='E'||s4[2]=='D')) return 1;
    else return 0;
}
bool islin(string s3,string s4)
{
    if((s3[2]=='A'||s3[2]=='B')&&(s4[2]=='A'||s4[2]=='B')) return 1;
    else if((s3[2]=='C'||s3[2]=='B')&&(s4[2]=='C'||s4[2]=='B')) return 1;
    else if((s3[2]=='E'||s3[2]=='D')&&(s4[2]=='E'||s4[2]=='D')) return 1;
    else return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            if(isce(s1,s2))
            {
                if(islin(s1,s2))
                {
                    cout<<"1111";
                }
                else cout<<"1110";
            }
            else cout<<"1100";
        }
        else cout<<"1000";
    }
    else cout<<"0000";
    return 0;
}
