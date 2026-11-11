#include<bits/stdc++.h>
using namespace std;
string s1,s2,r1,r2;
bool chexiang(string x,string y)
{
    for(int i=0;i<x.size();i++) if(x[i]!=y[i]) return 0;
    return 1;
}
bool pai(string x,string y)
{
    for(int i=0;i<2;i++) if(x[i]!=y[i]) return 0;
    return 1;
}
bool ce(string x,string y)
{
    char xx=x[2],yy=y[2];
    if(xx=='A' && (yy=='B' || yy=='C')) return 1;
    else if(xx=='B' && (yy=='A' || yy=='C')) return 1;
    else if(xx=='C' && (yy=='B' || yy=='A')) return 1;
    else if(xx=='D' && yy=='F') return 1;
    else if(xx=='F' && yy=='D') return 1;
    else return 0;
}
bool ling(string x,string y)
{
    char xx=x[2],yy=y[2];
    if(xx=='A' && yy=='B') return 1;
    else if(xx=='B' && (yy=='A' || yy=='C')) return 1;
    else if(xx=='C' && yy=='B') return 1;
    else if(xx=='D' && yy=='F') return 1;
    else if(xx=='F' && yy=='D') return 1;
    else return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>r1>>r2;
    if(chexiang(s1,r1)==1)
    {
        cout<<"1";
        if(pai(s2,r2)==1)
        {
            cout<<"1";
            if(ce(s2,r2)==1)
            {
                cout<<"1";
                if(ling(s2,r2)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
