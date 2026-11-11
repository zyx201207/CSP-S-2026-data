#include <bits/stdc++.h>
using namespace std;
int rh,xh,cnt;
string rz,xz;
char r,x;
int main () {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>rh>>rz>>xh>>xz;
    if(rh==xh) cout<<1;
    else {
        cout<<0<<0<<0<<0;
        return 0;
    }
    for(int i=0; i<rz.size(); i++) {
        if(i<rz.size()-1) {
            if(rz[i]==xz[i]) cnt++;
        }else {
            r+=rz[i];
            x+=xz[i];
        }
    }
    if(cnt==2) cout<<1;
    else {
        cout<<0<<0<<0;
        return 0;
    }
    if(((r=='F'||r=='D')&&(x=='F'||x=='D'))||((r=='A'||r=='B'||r=='C')&&(x=='A'||x=='B'||x=='C'))) {
        cout<<1;
    }else {
        cout<<0<<0;
        return 0;
    }
    if(((r=='F'&&x=='D')||(r=='D'&&x=='D'))||((r=='A'&&x=='B')||(r=='B'&&x=='C')||(r=='C'&&x=='B')||(r=='B'&&x=='A'))) {
        cout<<1;
    }else cout<<0;
    return 0;
}
