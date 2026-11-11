#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c)
    {
        cout<<1;
        if(b.substr(0,2)==d.substr(0,2))
        {
            cout<<1;
            int x=b[2]-'A';
            int y=d[2]-'A';
            if((x<=2&&y>2)||(y<=2&&x>2)) cout<<"00";
            else
            {
                cout<<1;
                if(x-y==1||x-y==-1) cout<<1;
                else cout<<0;
            }
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
