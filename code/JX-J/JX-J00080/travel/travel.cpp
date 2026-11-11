#include<bits/stdc++.h>
using namespace std;

int main()
{
    freeopen("travel.in","r",stdin);
    freeopen("travel.out","w",stdout);
   string a,b,c,d;
   cin>>a>>b>>c>>d;
   if(a==c)
   {
       if(b[1]==d[1]&&b[2]==d[2])
       {
            if(((b[3]=='A'||b[3]=='B'||b[3]=='C')&&(d[3]=='A'||d[3]=='B'||d[3]=='C'))||((b[3]=='D'||b[3]=='E')&&(d[3]=='E'||d[3]=='D')))
           {
            cout<<'1111';
           }
           else{
            cout<<'1110';
           }

       }
       else
       {
           cout<<'1000';
       }
   }
   else
   {
       cout<<'0000';
   }
    return 0;
}
