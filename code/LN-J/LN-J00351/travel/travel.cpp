#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    bool q1=1,q2=1,q3=0,q4=0;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<=1;i++)
    {
        if(c1[i]!=c2[i])
            q1=0;
    }
    if(q1)
    {
        for(int i=0;i<=1;i++)
            if(s1[i]!=s2[i])
                q2=0;
    }
    else q2=0;
    if(q2)
    {
        if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
            q3=1;
        else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
            q3=1;
    }
    if(q3)
    {
        if(s1[2]=='F')s1[2]='E';
        if(s2[2]=='F')s2[2]='E';
        if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
            q4=1;
    }
    cout<<q1<<q2<<q3<<q4;

    return 0;
}
