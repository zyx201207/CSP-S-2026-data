#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,b;
    string c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(c[0]==d[0] and d[1]==c[1]){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    if(((c[2]=='A' or c[2]=='B' or c[2]=='C') and (d[2]=='A' or d[2]=='B' or d[2]=='C')) or ((c[2]=='E' or c[2]=='D') and (d[2]=='E' or d[2]=='D'))){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if( (c[2]-d[2]==1 or c[2]-d[2]==-1) and ((c[2]!='D' and d[2]!='C') or (d[2]!='D' and c[2]!='C'))){
        cout<<1;
    }
    else{
        cout<<'0';
        return 0;
    }
    return 0;
}
