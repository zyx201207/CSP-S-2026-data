#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2) cout<<"0000";
    else 
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            int k1=s1[2]-'A';
            int k2=s2[2]-'A';
            if(k1<=2&&k2>2) cout<<"00";
            else if(k1>2&&k2<=2) cout<<"00";
            else
            {
                cout<<1;
                if(abs(k1-k2)==1) cout<<1;
                else if(s1[2]=='D'&&s2[2]=='F') cout<<1;
                else if(s1[2]=='F'&&s2[2]=='D') cout<<1;
                else cout<<0;
            }
        }
        else cout<<"000";
    }
    return 0;
}