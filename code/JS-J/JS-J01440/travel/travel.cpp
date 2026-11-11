#include <bits/stdc++.h>
using namespace std;
string c1,d1,c2,d2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>d1>>c2>>d2;
    char x=d1[3],y=d2[3];
    if(c1==c2)
    {
        cout<<"1";
        if(d1[1]==d2[1]&&d1[2]==d2[2])
        {
            cout<<"1";
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
