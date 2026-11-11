#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    char a4,b4;
    int a2,a3,b2,b3;
    cin>>a>>a1>>b>>b1;
    a2=(a[0]-'0')*10+a[1]-'0';
    b2=(b[0]-'0')*10+b[1]-'0';
    if(a2!=b2)
    {
        cout<<"0000"<<endl;
        return 0;
    }
    cout<<"1";
    a3=(a1[0]-'0')*10+a1[1]-'0';
    b3=(b1[0]-'0')*10+b1[1]-'0';
    if(a3!=b3)
    {
        cout<<"000"<<endl;
        return 0;
    }
    cout<<"1";
    a4=a1[2]-'0';
    b4=b1[2]-'0';
    if(b4==20||b4==22)
    {
        if(a4==17||a4==18||a4==19)
        {
            cout<<"00"<<endl;
            return 0;
        }
        else
        {
            cout<<"11"<<endl;
            return 0;
        }
    }
    if(b4==17||b4==18||b4==19)
    {
        if(a4==20||a4==22)
        {
            cout<<"00"<<endl;
            return 0;
        }
        cout<<"1";
    }
    if(a4==18||b4==18)
    {
        cout<<"1"<<endl;
        return 0;
    }
    else
    {
        cout<<"0"<<endl;
        return 0;
    }
}
