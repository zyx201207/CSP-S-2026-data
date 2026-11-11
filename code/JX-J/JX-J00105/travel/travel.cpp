#include<bits/stdc++.h>
using namespace std;
char a[20],b[20],c[20],d[20];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int pd=1;
    for(int i=0;i<=1;i++)
    {
        if(a[i]!=c[i])
        {
            pd=0;
            break;
        }
    }
    if(pd==1)cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    pd=1;
    //1

    for(int i=0;i<=1;i++)
    {
        if(d[i]!=b[i])
        {
            pd=0;
            break;
        }
    }
    if(pd==1)cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    pd=1;
    //2

    if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')//3/2
    {

       cout<<1;


        if(b[2]-d[2]==1||b[2]-d[2]==-1)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<0;
            return 0;
        }//4
    }
    else
        {
           if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')
            {

                cout<<"11";
                return 0;
            }
            else
            {

                cout<<"00";
                return 0;
            }
        }
    return 0;
}
