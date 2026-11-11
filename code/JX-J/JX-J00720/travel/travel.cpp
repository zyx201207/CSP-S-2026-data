#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
        cout<<"1";
        long long sum1=0,sum2=0;
        sum1=s1[2]-'A';
        sum2=s2[2]-'A';
        if(sum1==4&&sum2==3)
        {
            cout<<"11";
        }else if(sum1==3&&sum2==4)
        {
            cout<<"11";
        }else
        {
            if(sum1>2 || sum2>2)cout<<"00";
            else
            {
                cout<<"1";
                if(abs(sum1-sum2)==1)cout<<"1";
                else cout<<"0";
            }
        }
     }else cout<<"000";
    }
    else cout<<"0000";

    return 0;
}
