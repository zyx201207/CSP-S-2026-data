#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<"0000";
    else
    {
        if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
        else
        {
            bool x=0,r=0;
            if(s1[2]!='F'&&s1[2]!='D')r=1;
            if(s2[2]!='F'&&s2[2]!='D')x=1;
            if(x!=r)cout<<"1100";
            else
            {
                if(r==0)cout<<"1111";
                else
                {
                    if(s1[2]-s2[2]==2)cout<<"1110";
                    else cout<<"1111";
                }
            }
        }
    }
    return 0;
}
