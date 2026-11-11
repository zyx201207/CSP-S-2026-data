#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
int x=0,y=0,z=0,o=0;
string a,b,c,d;
cin >>a>>b>>c>>d;

if(a==c)
{
    x++;
    if(b[0]==d[0]&&b[1]==d[1])
    {
        y++;
        if(b[2]+'0'<=115&&d[2]+'0'<=115)
            {
                z++;
                if(b[2]=='A'&&d[2]=='B')
                {
                    o++;
                }
                else if(b[2]=='B'&&d[2]=='A')
                {
                    o++;
                }
                else if(b[2]=='B'&&d[2]=='C')
                {
                    o++;
                }
                else if(b[2]=='C'&&d[2]=='B')
                {
                    o++;
                }
            }
            else
            {
               if(b[2]=='D'&&d[2]=='F')
               {
                   o++;
               }
               else if(b[2]=='F'&&d[2]=='D')
               {
                   o++;
               }
            }
    }
}
cout<<x<<y<<z<<o;
fclose(stdin);
fclose(stdout);
return 0;
}

