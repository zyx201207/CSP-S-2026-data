#include<bits/stdc++.h>
using namespace std;
bool a[5]={1,1,1,1};
int b[3];
int c[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    int flag=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        for(int i=0;i<2;i++)
        {
            b[i]=s1[i]-'0';
            c[i]=s2[i]-'0';
        }
        for(int i=0;i<2;i++)
        {
            if(b[i]!=c[i])
            {
                a[1]=0;
                a[2]=0;
                a[3]=0;
            }
        }
        if(a[2]!=0)
        {
          if(s1[2]<69 && s2[2]<69)
        {
            if(s1[2]>s2[2])
            {
                if(s1[2]-1!=s1[2])a[3]=0;
            }
            else if(s1[2]<s2[2])
            {

                if(s2[2]-1!=s1[2])a[3]=0;
            }
        }
        if(s1[2]>=69 && s2[2]>=69)
        {
             if(s1[2]>s2[2])
            {
                if(s1[2]-1!=s1[2])a[3]=0;
            }
            else if(s1[2]<s2[2])
            {

                if(s2[2]-1!=s1[2])a[3]=0;
            }
        }
        if(s1[2]=='C' && s2[2]=='D'){
            a[2]=0;
            a[3]=0;
        }
        if(s1[2]=='D' && s2[2]=='C')
        {
            a[2]=0;
            a[3]=0;
        }
    }

        }

    else {
        cout<<"0000";
        return 0;
    }
    for(int i=0;i<4;i++)
    {
        cout<<a[i];
    }
    return 0;
}
