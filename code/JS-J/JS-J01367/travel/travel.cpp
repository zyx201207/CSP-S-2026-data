#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int ana = 0,anb = 0;
    ana = 10*int(a[0]-'0') + int(a[1] - '0');
    anb = 10*int(c[0]-'0') + int(c[1] - '0');
    if(ana == anb)cout<<1;
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    ana = 10*int(b[0]-'0') + int(b[1] - '0');
    anb = 10*int(d[0]-'0') + int(d[1] - '0');
    if(ana == anb)cout<<1;
    else{
        cout<<0<<0<<0;
        return 0;
    }
    if(((b[2] == 'D' || b[2] == 'F') && (d[2] == 'D' || d[2] == 'F')) || ((b[2] == 'A' || b[2] == 'B'||b[2] == 'C')&&(d[2] == 'A'||d[2] == 'B'||d[2] == 'C')))cout<<1;
    else{
        cout<<0<<0;
        return 0;
    }
    if((b[2] == 'A' && d[2] == 'B')||(b[2] == 'B' && d[2] == 'A')||(b[2] == 'B' && d[2] == 'C')||(b[2] == 'C' && d[2] == 'B')||(b[2] == 'D' && d[2] == 'F')||(b[2] == 'F' && d[2] == 'D')){
        cout<<1;
    }else{
        cout<<0;
    }
}
