#include<bits/stdc++.h>
using namespace std;
bool a2(string b,string d){
    if(b[1]==d[1]) return 1;
    else return 0;
}bool a3(string b,string d){
    if(!(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C')) return 1;
    else return 0;
}bool a4(string b,string d){
    if(b[2]-d[2]==1||d[2]-b[2]==1) return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        if(a2(b,d)){
            cout<<1;
            if(a3(b,d)){
                cout<<1;
                if(a4(b,d)){
                    cout<<1;
                    return 0;
                }else{
                    cout<<0;
                    return 0;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
