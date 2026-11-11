#include<bits/stdc++.h>
using namespace std;
int x,y;
string s1,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>s1>>y>>s2;
    if(x!=y)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<1;
    if(s1[0]!=s2[0]||s1[1]!=s2[1])
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<1;
    if((bool)(s1[2]<='C')!=(bool)(s2[2]<='C'))
    {
        cout<<"00"<<endl;
        return 0;
    }
    cout<<1;
    if(s1[2]-s2[2]!=1&&s1[2]-s2[2]!=-1)
    {
        cout<<0;
        return 0;
    }
    cout<<1<<endl;
    return 0;
}
