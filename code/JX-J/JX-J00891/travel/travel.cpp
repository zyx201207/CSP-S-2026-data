#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r".stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<'\n';
        return 0;
    }
    else
    {
        bool flag=false;
        for(int i=0;i<2;i++)
        {
            if(s1[i]!=s2[i])
            {
                cout<<"1000"<<'\n';
                return 0;
            }
        }
        if((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='D'||s1[2]=='F')))flag=true;
        else
        {
            cout<<"1100"<<'\n';
            return 0;
        }
        int a=s1[2]-'0';
        int b=s2[2]-'0';
        if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')
        {
            if(abs(a-b)==1)cout<<"1111"<<'\n';
            else cout<<"1110"<<'\n';
        }
        else if((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='D'||s1[2]=='F'))
        {
            if(abs(a-b)==2)cout<<"1111"<<'\n';
            else cout<<"1110"<<'\n';
        }
    }
    return 0;
}
/*02 01A 02 01B*/
