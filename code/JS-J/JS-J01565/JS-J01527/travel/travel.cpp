#include<bits/stdc++.h>
using namespace std;
string  c1,s1,c2,s2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            int t1,t2;
            if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
            {
                t1 = 1;
            }
            else
            {
                t1 = 2;
            }
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
            {
                t2 = 1;
            }
            else
            {
                t2 = 2;
            }
            if(t1==t2)
            {
                cout<<1;
                int k=abs(s1[2]-s2[2]);
                if(k==1)
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            else
            {
                cout<<"00";
            }
        }
        else
        {
            cout<<"000";
        }
    }
    else
    {
        cout<<"0000";
    }
    return 0;
}
