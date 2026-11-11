#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    string s="",t="";
    if(a==c){
        cout<<1;
        s=s+b[0]+b[1],t=t+d[0]+d[1];
        if(s==t){
            cout<<1;
            if((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')){
                cout<<1;
                if(abs(int(b[2]-d[2]))==1||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
