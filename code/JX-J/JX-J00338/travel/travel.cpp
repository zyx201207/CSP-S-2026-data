#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    char b[3],d[3];
    int f=0,y=0,r=0,u=0;
    cin>>a>>b>>c>>d;
    if(a!=c)f=0;
    else{
        f=1;
        if(b[0]!=d[0]||b[1]!=d[1])y=0;
        else{
            y=1;
            if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F'))||((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')))r=0;
            else{
                r=1;
                if(b[2]=='D'||b[2]=='F'||(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='A'||b[2]=='C'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'))u=1;
                else u=0;
            }
        }
    }
    cout<<f<<y<<r<<u<<endl;
    return 0;

}
