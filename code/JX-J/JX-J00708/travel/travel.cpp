#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a1=0,b1=0,c1=0,d1=0;
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        a1=0;
        cout<<a1<<"000";
        return 0;
    }
    else a1=1;
    if(b[0]==d[0] && b[1]==d[1]){
       b1=1;
       if(b[2]<='C' && b[2]>='A' && d[2]<='C' && d[2]>='A' || b[2]<='F' && b[2]>='D' && d[2]<='F' && d[2]>='D'){
            c1=1;
            if(b[2]=='C' && d[2]=='B' || b[2]=='B' && d[2]=='C' || b[2]=='B' && d[2]=='A' || b[2]=='A' && d[2]=='B' || b[2]=='D' && d[2]=='F' || b[2]=='F' && d[2]=='D'){
                d1=1;
            }else{
                d1=0;
                cout<<a1<<b1<<c1<<d1;
                return 0;
            }
       }else{
        c1=0;
        cout<<a1<<b1<<c1<<"0";
        return 0;
       }
    }
    else{
      cout<<a1<<b1<<"00";
      return 0;
    }
    cout<<a1<<b1<<c1<<d1;
    return 0;
}
