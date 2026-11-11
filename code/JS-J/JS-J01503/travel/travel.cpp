#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char n[10],m[10];
    cin>>a>>n>>b>>m;
    if(a == b)
        {
            cout<<"1";
            if(n[0] == m[0]&&n[1] == m[1])
            {
                cout<<"1";
                if((n[2]<='C'&&m[2]<='C')||(n[2]>='D'&&m[2]>='D'))
                {
                    cout<<"1";
                    if(n[2] == m[2]-1||n[2] == m[2]+1)
                        cout<<"1";
                    else
                        cout<<"0";
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
