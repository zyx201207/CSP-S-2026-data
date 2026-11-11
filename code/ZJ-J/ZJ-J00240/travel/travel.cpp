#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=1e6+10;
int a[maxn];
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if((s1[2]+s2[2]=='D'+'F')||(s1[2]!='D'&&s1[2]!='F'&&s2[2]!='D'&&s2[2]!='F'))
            {
                cout<<1;
                if(s1[2]=='A'&&s2[2]!='B')cout<<0;
                else if(s1[2]=='B'&&(s2[2]!='A'||s2[2]!='C'))cout<<0;
                else if(s1[2]=='C'&&s2[2]!='B')cout<<0;
                else if(s1[2]=='F'&&s2[2]!='E')cout<<0;
                else if(s1[2]=='E'&&s2[2]!='f')cout<<0;
                else cout<<1;
            }
            else cout<<"00";
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
