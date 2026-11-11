#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int mchws[4]={65*66,66*67,68*70};
    char c1[5],s1[5],c2[5],s2[5];
    cin>>c1>>s1>>c2>>s2;
    int x=int(s1[2]);
    int y=int(s2[2]);
    if(c1[0]==c2[0] && c1[1]==c2[1])
    {
        cout<<1;
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            cout<<1;
            if((x<68 && y<68) || (x>=68 && y>=68))
            {
                cout<<1;
                int k=x*y;
                if(k==mchws[0] || k==mchws[1] || k==mchws[2]) cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
