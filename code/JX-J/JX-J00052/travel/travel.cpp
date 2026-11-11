#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
char c,d;
int a,b,flag=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3) cout<<"1";
    else{
        cout<<"0000";
        return 0;
    }
    a=(c2[0]-'0')*10+(c2[1]-'0');
    c=c2[2];
    b=(c4[0]-'0')*10+(c4[1]-'0');
    d=c4[2];
    if(a==b) cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if((c=='F' && d=='D')||(d=='F' && c=='D')||(c=='A' && d=='B')||(c=='A' && d=='C')||(c=='B' && d=='A')||(c=='B' && d=='C')||(c=='C' && d=='A')||(c=='C' && d=='B')) cout<<"1";
    else{
        cout<<"00";
        return 0;
    }
    if((c=='F' && d=='D')||(d=='F' && c=='D')||(c=='A' && d=='B')||(c=='B' && d=='A')||(c=='B' && d=='C')||(c=='C' && d=='B')) cout<<"1";
    else cout<<"0";
    return 0;
}
