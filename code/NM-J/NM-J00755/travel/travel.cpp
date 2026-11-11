#include<bits/stdc++.h>
using namespace std;
string r,a,x,b;
string out;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>r>>a>>x>>b;
    if(r!=x){
        out="0000";
        cout<<out;
        return 0;
    }else if(b<a){
        out="1110";
        cout<<out;
        return 0;
    }else if(a<b){
        out="1100";
        cout<<out;
        return 0;
    }else if(r==x){
        out="1111";
        cout<<out;
        return 0;
    }else{
        out="1000";
    }
    cout<<out;
    return 0;
}
