#include<bits/stdc++.h>
using namespace std;
int check(string a,string b)
{
    if(a.size()==3&&b.size()==3)
    {
        char a2=a[1],b2=b[1];
        if(a2!=b2)
        {
            cout<<"000";
            return 0;
        }
        cout<<1;
        a2=a[2],b2=b[2];
        if(a2>='D'&&b2<='C'||a2<='C'&&b2>='D')
        {
            cout<<"00";
            return 0;
        }
        cout<<1;
        if(abs(a2-b2)>1)
        {
            cout<<0;
            return 0;
        }
        cout<<1;
    }
    else
    {
        if(a.size()!=b.size())
        {
            cout<<"000";
            return 0;
        }
        char a2=a[1],b2=b[1],a3=a[2],b3=b[2];
        if(a3!=b3)
        {
            cout<<"000";
            return 0;
        }
        cout<<1;

        a2=a[3],b2=b[3];
        if(a2>='D'&&b2<='C'||a2<='C'&&b2>='D')
        {
            cout<<"00";
            return 0;
        }
        cout<<1;
        if(abs(a2-b2)>1)
        {
            cout<<0;
            return 0;
        }
    }

}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,a1,b1;
    cin>>a>>a1>>b>>b1;
    if(a!=b)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    check(a1,b1);
    return 0;
}
