#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c) cout<<"0000"<<endl;
    else
    {
        cout<<"1";
        if(b[0]!=d[0]||b[1]!=d[1]) cout<<"000"<<endl;
        else
        {
            cout<<"1";
            int x=int(b[2]);
            int y=int(d[2]);
            if((x<=67&&y>67)||(y<=67&&x>67)) cout<<"00"<<endl;
            else
            {
                cout<<"1";
                if(abs(x-y)==1) cout<<"1"<<endl;
                else cout<<"0"<<endl;
            }
        }
    }
    return 0;
}
