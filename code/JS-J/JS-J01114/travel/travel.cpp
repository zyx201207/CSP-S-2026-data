#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long ans=0;
string r1,r2,x1,x2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r1>>r2>>x1>>x2;
    if(r1==x1)
    {
        if(r2[0]==x2[0]&&r2[1]==x2[1])
        {
            if(r2[2]=='A'&&x2[2]=='B')
            {
                cout<<"1111";
                return 0;
            }
            else if(r2[2]=='A'&&x2[2]=='c')
            {
                cout<<"1110";
                return 0;
            }
            else if(r2[2]=='B'&&x2[2]=='A')
            {
                cout<<"1111";
                return 0;
            }
            else if(r2[2]=='B'&&x2[2]=='C')
            {
                cout<<"1111";
                return 0;
            }
            else if(r2[2]=='C'&&x2[2]=='A')
            {
                cout<<"1110";
                return 0;
            }
            else if(r2[2]=='C'&&x2[2]=='B')
            {
                cout<<"1111";
                return 0;
            }
            else if(r2[2]=='D'&&x2[2]=='F')
            {
                cout<<"1111";
                return 0;
            }
            else if(r2[2]=='F'&&x2[2]=='D')
            {
                cout<<"1111";
                return 0;
            }
            else
            {
                cout<<"1100";
                return 0;
            }
        }
        else
        {
            cout<<"1000";
            return 0;
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }


    return 0;
}
