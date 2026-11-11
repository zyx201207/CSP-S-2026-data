#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,int>mp={{'A',1},{'B',1},{'C',1},{'D',2},{'F',2}};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
    }else if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"1000";
    }else if(mp[b[2]]!=mp[d[2]]){
        cout<<"1100";
    }else if(mp[b[2]]!=2&&abs(b[2]-d[2])!=1){
        cout<<"1110";
    }else{
        cout<<"1111";
    }
    return 0;
}
