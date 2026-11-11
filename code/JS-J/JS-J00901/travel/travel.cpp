#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rc,rz,xc,xz;
    cin>>rc>>rz>>xc>>xz;
    int rh=(rz[0]-'0')*10+(rz[1]-'0'),xh=(xz[0]-'0')*10+(xz[1]-'0');
    char rl=rz[2],xl=xz[2];
    if(rc==xc) cout<<1;
    else cout<<0;
    if(rc==xc&&rh==xh) cout<<1;
    else cout<<0;
    if(rc==xc&&rh==xh)
    {
        if(rl<='C'&&xl<='C'||rl>='D'&&xl>='D') cout<<1;
        else cout<<0;
    }
    else cout<<0;
    if(rc==xc&&rh==xh)
    {
        if(rl<='C'&&xl<='C'||rl>='D'&&xl>='D')
        {
            if(rl+1==xl||rl-1==xl) cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
