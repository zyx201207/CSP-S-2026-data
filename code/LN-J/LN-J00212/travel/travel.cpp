#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,x,b,y;
    cin>>a>>x>>b>>y;
    if(a==b) cout<<1;
    else{
        cout<<"0000";
        return 0;
    }
    string p=x.substr(0,2);
    string q=y.substr(0,2);
    if(p==q) cout<<1;
    else{
        cout<<"000";
        return 0;
    }
    string u=x.substr(2);
    string v=y.substr(2);
    if(u=="A" && v=="B" || u=="B" && v=="A" || u=="A" && v=="C" ||
       u=="C" && v=="A" || u=="D" && v=="F" || u=="F" && v=="D" ||
       u=="C" && v=="B" || u=="B" && v=="C"){
        cout<<1;
    }else{
        cout<<"00";
        return 0;
    }
    if(u=="A" && v=="B" || u=="B" && v=="A" || u=="B" && v=="C" ||
       u=="C" && v=="B" || u=="D" && v=="F" || u=="F" && v=="D"){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
