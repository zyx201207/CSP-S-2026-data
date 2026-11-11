#include<bits/stdc++.h>
using namespace std;
bool ck(string a,string b){
    if(a=="A"&&b=="B") return 1;
    if(a=="A"&&b=="C") return 1;
    if(a=="B"&&b=="A") return 1;
    if(a=="B"&&b=="C") return 1;
    if(a=="C"&&b=="A") return 1;
    if(a=="C"&&b=="B") return 1;
    if(a=="D"&&b=="F") return 1;
    if(a=="F"&&b=="D") return 1;
}
bool ch(string a,string b){
    if(a=="A"&&b=="B") return 1;
    if(a=="B"&&b=="A") return 1;
    if(a=="B"&&b=="C") return 1;
    if(a=="C"&&b=="B") return 1;
    if(a=="D"&&b=="F") return 1;
    if(a=="F"&&b=="D") return 1;
}
signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>c>>b>>d;
    if(a==b){
        cout<<1;
        if(c.substr(0,2)==d.substr(0,2)){
            cout<<1;
            if(ck(c.substr(2),d.substr(2))){
                cout<<1;
                if(ck(c.substr(2),d.substr(2))){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
