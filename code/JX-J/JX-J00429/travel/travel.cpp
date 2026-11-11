#include <bits/stdc++.h>
using namespace std;
int main()
{

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1;
    string s1;
    string c2;
    string s2;
    cin >>c1>>s1>>c2>>s2;
    int a [4];
    for(int i =0;i<4;i++)
    {
        a[i]=0;
    }
    for(int j =0;j<2;j++)
    {
        if(c1[j]!=c2[j])
        {
            a[j]=0;
            for(int m=0;m<4;m++)
            {
            cout<<a[m];
            }
            return 0;
        }
    }
    a[0] = 1;
     if(s1[1]!=s2[1])
    {
        a[1]=0;
        for(int m=0;m<4;m++)
            {
                cout<<a[m];
            }
            return 0;
    }
    for(int j =1;j<3;j++)
    {
        if(s1[j-1]!=s2[j-1])
        {
            a[j]=0;
            for(int m=0;m<4;m++)
            {
                cout<<a[m];
            }
            return 0;
        }
    }
    a[1]=1;
    if(s1[2]=='F'&&s2[2]=='D')
    {
        a[2]=1;
    }
    else if (s1[2]=='D'&&s2[2]=='F')
    {
        a[2]=1;
    }
    else if (s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {
        if(s2[2]=='B'||s2[2]=='C'||s2[2]=='A')
        {
            a[2]=1;
        }
    }
    else
    {
        a[2]=0;
        for(int m=0;m<4;m++)
        {
            cout<<a[m];
        }
        return 0;
    }
    if((s1[2]=='F'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='F'))
    {
        a[3]=1;
    }
    else if(s1[2]=='B')
    {
        if(s2[2]=='A'||s2[2]=='C')
        {
                a[3]=1;
        }
    }
    else if(s2[2]=='B')
    {
        if(s1[2]=='A'||s1[2]=='C')
        {
            a[3]=1;
        }
    }
    else
    {
        a[3]=0;
    }
   for(int m=0;m<4;m++)
            {
            cout<<a[m];
            }
            return 0;
    return 0;

}
