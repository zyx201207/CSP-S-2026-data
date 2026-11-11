#include <bits/stdc++.h>
#define s string
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    s a,b,c,d;
    bool e = false,f = false,g = false,h = false;
    cin>>a>>b>>c>>d;
    if(a==c){
        e=true;
        if(b.substr(0,2)==d.substr(0,2)){
            f=true;
            if(b[2]<='C'&&d[2]<='C'){
                g=true;
                if(b[2]=='B'||d[2]=='B'){
                    h=true;
                }
            }
            if(b[2]>'C'&&d[2]>'C'){
                g=true;
                h=true;
            }
        }
    }
    cout<<e<<f<<g<<h;
    return 0;
}
