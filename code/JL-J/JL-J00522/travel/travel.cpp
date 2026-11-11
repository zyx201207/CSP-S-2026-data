#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    if(b[0]!=d[0]||b[1]!=d[1]){
        cout<<"1000";
        return 0;
    }
    int x=1,y=1;
    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
        x=0;
    }
    if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
        y=0;
    }
    if(x!=y){
        cout<<"1100";
        return 0;
    }
    if(x){
        cout<<"1111";
        return 0;
    }
    if(abs(d[2]-b[2])==1){
        cout<<"1111";
        return 0;
    }else{
        cout<<"1110";
        return 0;
    }
    return 0;
}
