#include <bits/stdc++.h>
using namespace std;
string r,x,rs,xs,rss,xss;
int main ()
{
    cin >>r>>rs>>x>>xs;
    if (r==x){
        rss=rs[0]+rs[1];
        xss=xs[0]+xs[1];
        cout <<"1";
        if (rss==xss){
            cout <<"1";
            if((rs[2]<='C'&&xs[2]<='C')||(rs[2]>'C'&&xs[2]>'C'))
            {
                cout <<"1";
                if ((rs[2]=='A'&&xs[2]=='B')||(rs[2]=='B'&&xs[2]=='A')||(rs[2]=='B'&&xs[2]=='C')||(rs[2]=='C'&&xs[2]=='B')||(rs[2]=='D'&&xs[2]=='F')||(rs[2]=='F'&&xs[2]=='D'))
                {
                    cout <<"1";
                }
                else{
                    cout <<"0";
                }
            }
            else{
                cout <<"00";
            }
        }
        else{
            cout <<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
