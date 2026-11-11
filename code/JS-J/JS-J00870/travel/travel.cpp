#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int vis(char c)
{
    if(c<='C') return 1;
    return 2;
}
int pos(char c)
{
    if(c<='D') return c-'A'+1;
    return c-'A';
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1)
    {
        cout<<"1";
        if(a2[0]==b2[0]&&a2[1]==b2[1])
        {
            cout<<"1";
            if(vis(a2[2])==vis(b2[2]))
            {
                cout<<"1";
                if(abs(pos(a2[2])-pos(b2[2]))==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
