#include<bits/stdc++.h>
using namespace std;
string sc,ss,ec,es;
//Hello CCF
//This is my last to join the CSP-J
//I hope rp++
//wang hou kan you cai dan
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>sc>>ss>>ec>>es;
    bool f1=0,f2=0,f3=0;
    if(sc==ec){
        cout<<1;
    }else{
        cout<<0;
        f1=1;
    }

    string str1=ss.substr(0,2);
    string str2=es.substr(0,2);
    if(str1==str2&&f1==0){
        cout<<1;
    }else{
        cout<<0;
        f2=1;
    }

    if(ss[2]>='A'&&ss[2]<='C'&&es[2]>='A'&&es[2]<='C'&&f2==0){
        cout<<1;
        if((ss[2]=='A'&&es[2]=='B')||(ss[2]=='B'&&es[2]=='A')){
            cout<<1;
            return 0;
        }else if((ss[2]=='C'&&es[2]=='B')||(ss[2]=='B'&&es[2]=='C')){
            cout<<1;
            return 0;
        }else{
            cout<<0;
            return 0;
        }
    }
    else if((ss[2]=='D'&&es[2]=='F')||(ss[2]=='F'&&es[2]=='D')&&f2==0){
        cout<<1;
        cout<<1;
        return 0;
    }
    else{
        cout<<0;
        cout<<0;
    }
    return 0;
}
