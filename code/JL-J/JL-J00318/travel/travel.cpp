#include<bits/stdc++.h>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool x=1,y=1;
    if(a==c){
        cout<<1;
    }
    else{
        cout<<0;
        x=0;
        y=0;
    }
    if(x&&(b[0]==d[0]&&b[1]==d[1])){
        cout<<1;
    }
    else{
        cout<<0;
        x=0;
        y=0;
    }
    if(x)
        if(b[2]<d[2]&&(b[2]>='D'||d[2]<='C')||(b[2]>d[2]&&(b[2]<='C'||d[2]>='D'))){
            cout<<1;
        }
        else{
            cout<<0;
        }
    else{
        cout<<0;
    }
    if(y){
        if((b[2]+1==d[2]||d[2]+1==b[2])&&!(b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C')){
            cout<<1;
        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}
