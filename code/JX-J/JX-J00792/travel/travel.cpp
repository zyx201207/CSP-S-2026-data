#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int a,b,e,f;
char c[10],d[10];
cin>>a>>c>>b>>d;
e=c[0]+c[1];
f=d[0]+d[1];
if(a==b){cout<<1;
if(e==f)
{cout<<1;
if((c[2]<=67)&&(d[2]<=67))
{cout<<1;
if((c[2]+2==d[2])||(d[2]+2==c[2]))
    cout<<"0";
    else
        cout<<1;
}
else
    {if((c[2]>67)&&(d[2]>67))
    cout<<11;
    else
        cout<<"00";
    }
}
else
    cout<<"000";
}
else
    cout<<"0000";

return 0;}
