

#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
bool flag=1;
signed main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    int sum=b[0]*10+b[1];
    int ans=d[0]*10+d[1];
    if(a==c)
    {
        cout<<1;
    }
    else
        cout<<0;
    if(a==c)
    {
        for(int i=0;i<2;i++)
        {
            if(b[i]!=d[i])
            {
                flag=false;
            }
        }
        if(flag==true)
        {
            cout<<1;
        }
        else
            cout<<0;
    }
        if(a==c)
        {
           if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))
            {
                cout<<1;
            }
            else
                cout<<0;
        }
        else
            cout<<0;
    if(a==c)
    {
       if(b[2]==d[2])
       {
           if(sum==ans||sum==ans+1||sum==ans-1)
           {
                cout<<1;
           }
           else
            if(b[2]==d[2]+1||b[2]==d[2]-1)
           {
               if(!flag)
               {
                   if(sum==ans)
                   {
                       cout<<1;
                   }
                   else
                    cout<<0;
               }
           }
       }
    return 0;
}

