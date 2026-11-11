#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b,x,y;
    string c,d;
    cin>>a>>c>>b>>d;
    a=a%100;
    b=b%100;
    x=c.size();
    y=d.size();
    if(a==b){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
        if(c[0]=='0'&&d[0]=='0'){
            if(c[1]==d[1]){
                cout<<"1";
            }else{
                cout<<"000";
                return 0;
            }
        }
        if(c[0]=='1'&&d[0]=='1'){
            if(c[2]==d[2]){
                cout<<"1";
            }else{
                cout<<"000";
                return 0;
            }
        }
        if(c[2]=='A'&&d[2]=='B'||c[2]=='A'&&d[2]=='c'||c[2]=='B'&&d[2]=='C'||c[2]=='B'&&d[2]=='A'||c[2]=='C'&&d[2]=='A'||c[2]=='C'&&d[2]=='B'||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D'){
            cout<<"1";
        }else{
            cout<<"00";
            return 0;
        }
        if(c[2]=='A'&&d[2]=='B'||c[2]=='B'&&d[2]=='A'||c[2]=='B'&&d[2]=='C'||c[2]=='C'&&d[2]=='B'||c[2]=='D'&&d[2]=='F'||c[2]=='F'&&d[2]=='D'){
            cout<<"1";
        }else{
            cout<<"0";
        }
    return 0;
}
