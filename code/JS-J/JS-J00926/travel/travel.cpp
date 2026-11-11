#include <bits/stdc++.h>
using namespace std;
string c[2],s[2],a[10];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c[1]>>s[1]>>c[2]>>s[2];
    if(c[1][0]==c[2][0] && c[1][1]==c[2][1]){
        a[1]="1";
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(s[1][0]==s[2][0] && s[1][1]==s[2][1]){
        a[2]="1";
    }
    else{
        cout<<"1000";
        return 0;
    }
    char m=s[1][2],n=s[2][2];
    if((m=='C' && n=='D') || (m=='D' && n=='C')){
        cout<<"1100";
        return 0;
    }
    if(abs(m-n)!=1){
        cout<<"1110";
        return 0;
    }
    cout<<"1111";
    return 0;
}
