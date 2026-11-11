#include<bits/stdc++.h>
using namespace std;
string s,s1,a,a1;
bool b[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>a>>a1;
    if(s==a)
    {
        b[1]=true;
        if(s1[0]==a1[0]&&s1[1]==a1[1])
        {
            b[2]=1;
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'))
            {
                b[3]=1;
                if(s1[2]-'0'==a1[2]-'1'||s1[2]-'1'==a1[2]-'0')
                    b[4]=1;
            }
            else if((s1[2]=='D'&&a1[2]=='F')||(s1[2]=='F'&&a1[2]=='D'))
            {
                b[3]=1;
                b[4]=1;
            }
        }
    }
    cout<<b[1]<<b[2]<<b[3]<<b[4];
    return 0;
}
