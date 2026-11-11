#include<bits/stdc++.h>
using namespace std;
string a,b,d,f;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>d>>f;
    if(a!=d){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(b[1]!=f[1]||b[0]!=f[0]){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if(b[2]=='A'){
        if(f[2]=='B')cout<<11;
        if(f[2]=='C')cout<<10;
        if(f[2]=='D')cout<<"00";
        if(f[2]=='F')cout<<"00";
    }
    if(b[2]=='B'){
        if(f[2]=='A')cout<<11;
        if(f[2]=='C')cout<<11;
        if(f[2]=='D')cout<<"00";
        if(f[2]=='F')cout<<"00";
    }
    if(b[2]=='C'){
        if(f[2]=='B')cout<<11;
        if(f[2]=='A')cout<<10;
        if(f[2]=='D')cout<<"00";
        if(f[2]=='F')cout<<"00";
    }
    if(b[2]=='D'||b[2]=='F'){
        if(f[2]=='D'||f[2]=='F')
        cout<<11;
        else cout<<"00";
    }
    return 0;
}
