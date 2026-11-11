#include <iostream>
#include <string>
using namespace std;
int main()
{
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string jieguo;
    if(s1[2]=='F')
    {
        s1[2]='E';
    }
    if(s2[2]=='F')
    {
        s2[2]='E';
    }
    if(c1==c2)
    {
        jieguo[0]='1';
    }else{
        jieguo[0]='0';
    }
    if(jieguo[0]=='1'&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        jieguo[1]='1';
    }else{
        jieguo[1]='0';
    }
    if(((s1[2]-'A'>=3&&s2[2]-'A'>=3)||(s1[2]-'A'<=2&&s2[2]-'A'<=2))&&jieguo[1]=='1')
    {
        jieguo[2]='1';
    }else{
        jieguo[2]='0';
    }
    if(jieguo[2]=='1'&&(s1[2]-s2[2]==1||s1[2]-s2[2]==-1))
    {
        jieguo[3]='1';
        }else{
        jieguo[3]='0';
        }
for(int i=0;i<=3;i++)
{
    cout<<jieguo[i];
}
    return 0;
}
