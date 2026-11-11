#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string c,d;
    cin>>a>>b>>c>>d;
    if (a!=b)cout<<"0000";
    else {
        cout<<"1";
        if (c[0]!=d[0]||c[1]!=d[1])cout<<"000";
        else {
            cout<<"1";
            if ((c[2]-'0')/4!=(d[2]-'0')/4)cout<<"00";
                else{
                    cout<<"1";
                    if (c[2]-'0'+1==d[2]-'0'||c[2]-'0'==d[2]-'0'+1)cout<<"1";
                    else cout<<"0";
                }
        }
    }
    return 0;
}
