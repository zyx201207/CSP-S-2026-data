#include<bits/stdc++.h>
using namespace std;
pair<string,string> r,x;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r.first;
    cin>>r.second;
    cin>>x.first;
    cin>>x.second;
    if(r.first==x.first){
        cout<<'1';
    }
    else{
        cout<<"0000";
        return 0;
    }
    if(r.second[0]==x.second[0]&&r.second[1]==x.second[1]){
        cout<<'1';
    }
    else{
        cout<<"000";
        return 0;
    }
    pair<char,char> h;
    h.first=r.second[2];
    h.second=x.second[2];
    if((h.first<='C'&&h.second<='C')||(h.first>='D'&&h.second>='D')){
        cout<<'1';
    }
    else{
        cout<<"00";
        return 0;
    }
    int v;
    if(h.first>h.second) v=h.first-h.second;
    else v=h.second-h.first;
    if(v==1){
        cout<<'1';
    }
    else{
        cout<<"0";
        return 0;
    }
    return 0;
}
