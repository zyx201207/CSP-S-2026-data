#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int changee(char x){
    if(x=='A') return 1;
    if(x=='B') return 2;
    if(x=='C') return 3;
    if(x=='D') return 4;
    return 6;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a==c) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    if(b[0]==d[0]&&b[1]==d[1]) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    int s=changee(b[2]);
    int n=changee(d[2]);
    if(s<=3&&n<=3) cout<<"1";
    else if(min(s,n)==4&&max(s,n)==6) {
        cout<<"11";
        return 0;
    }
    else
    {
        cout<<"00";
        return 0;
    }
    if(min(s,n)==1&&max(s,n)==3) cout<<"0";
    else cout<<"1";
    return 0;
}
