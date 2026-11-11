#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4,s5,s6;
    cin>>s1>>s2>>s3>>s4;
    s5=s2.substr(0,2);
    s6=s4.substr(0,2);
    char c1=s2[2],c2=s4[2];
    if(c1=='F')c1='E';
    if(c2=='F')c2='E';
    if(s1!=s3)cout<<"0000";
    else if(s5!=s6)cout<<"1000";
    else
    {
        if(c1<'D'&&c2<'D'||c1>='D'&&c2>='D')
        {
            cout<<"111";
            if(c1<c2)swap(c1,c2);
            if(c1-c2==1&&c1!='D')
                cout<<"1";
            else
                cout<<"0";
        }
        else cout<<"1100";
    }
    return 0;
}
