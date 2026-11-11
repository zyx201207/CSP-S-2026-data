#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,az,b,bz;
cin>>a>>az>>b>>bz;
int len=az.length()-1;
for(int i=0;i<a.length();i++)
{
    if(a[i]!=b[i])
    {
        cout<<"0000";
        return 0;
    }
}
for(int i=0;i<len;i++)
{
    if(az[i]!=bz[i])
    {
        cout<<"1000";
        return 0;
    }
}
if((az[len]<='C'&&bz[len]<='C')||(az[len]>='D'&&bz[len]>='D'))
{
    if(az[len]-1==bz[len])
    {
        cout<<"1111";
    }
    else if(az[len]==bz[len]-1)
    {
         cout<<"1111";
    }
    else{
        cout<<"1110";
    }
}
else{
    cout<<"1100";
}
return 0;
}
