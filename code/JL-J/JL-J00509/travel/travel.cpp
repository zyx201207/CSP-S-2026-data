#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b;
int i,n,s=0;
cin>>i>>a>>n>>b;
if(i==n)
{
    cout<<"1";
    if(a[0]==b[0]&&a[1]==b[1])
    {
       cout<<"1";
        if(a[2]<'D'&&b[2]<'D'||a[2]>'C'&&b[2]>'C') {
                cout<<"1";
              if(int(a[2]-b[2]==1)||int(b[2]-a[2]==1))
              {
                  cout<<"1";
              }
             else cout<<"0";
        }
         else cout<<"00";
    }
    else cout<<"000";
}
else cout<<"000";

return 0;
}
