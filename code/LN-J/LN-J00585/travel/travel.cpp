#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);


    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
      cout<<0<<0<<0<<0;
    }
    else if(b[0]==d[0]&&b[1]==d[1]){
      if((b[2]==d[2]+1||b[2]==d[2]-1)&&(b[2]!='C'&&b[2]!='D')){
        cout<<1<<1<<1<<1;
      }
      else if((b[2]>'C'&&d[2]<'D')||(b[2]<'D'&&d[2]>'C')){
        cout<<1<<1<<0<<0;
      }
      else if((b[2]-d[2]>1||d[2]-b[2]>1)&&(b[2]>'C'&&d[2]>'C'||b[2]<'D'&&d[2]<'D')&&((b[2]!='D'&&d[2]!='F')&&(b[2]!='F'&&d[2]!='D'))){
        cout<<1<<1<<1<<0;
      }
      else if((b[2]=='F'&&d[2]=='D')||(b[2]=='D'&&d[2]=='F')){
        cout<<1<<1<<1<<1;
      }
    }
    else if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<1<<0<<0<<0;
    }
    return 0;
}
