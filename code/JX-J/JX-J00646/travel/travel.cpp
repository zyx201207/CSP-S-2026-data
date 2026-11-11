#include<bits/stdc++.h>
using namespace std;
int getSide(char c){
    if(c>='A'&&c<='C')return 1;
    return 2;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
    }else{
        cout<<1;
        if(b[0]!=d[0]||b[1]!=d[1]){
            cout<<"000";
        }else{
            cout<<1;
            if(getSide(b[2])!=getSide(d[2])){
                cout<<"00";
            }else{
                cout<<1;
                int seat1=b[2]-'A',seat2=d[2]-'A';
                if(abs(seat1-seat2)==1)cout<<1;
                else cout<<0;
            }
        }
    }
    return 0;
}
