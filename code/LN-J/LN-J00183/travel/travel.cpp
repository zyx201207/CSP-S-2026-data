#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,s1,s2,n;
    cin>>c1>>s1>>c2>>s2;
    if((c1[0]-'0')==(c2[0]-'0')&&(c1[1]-'0')==(c2[1]-'0'))
    {
        n[0]='1';
        if((s1[0]-'0')==(s2[0]-'0')&&(s1[1]-'0')==(s2[1]-'0'))
        {
            n[1]='1';
            if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
            {
                n[2]='1';
                if(abs(s1[2]-s2[2])==1)
                    n[3]='1';
                else
                    n[3]='0';
            }
            else  if((s1[2]=='E'||s1[2]=='F')&&(s2[2]=='E'||s2[2]=='F'))
            {
                n[2]='1';
                n[3]='1';
            }
            else
            {
                n[2]='0';
                n[3]='0';
            }
        }

        else
        {
            n[1]='0';
            n[2]='0';
            n[3]='0';
        }
    }
    else
    {
        n[0]='0';
        n[1]='0';
        n[2]='0';
        n[3]='0';
    }
    for(int i=0;i<4;i++)
        cout<<n[i];
    return 0;
}
