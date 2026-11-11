#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
string s,t;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> n >> s >> m >> t;
    if(n!=m){
        cout << "0000";
    }else if(s[0]!=t[0] || s[1]!=t[1]){
        cout << "1000";
    }else if((s[2]<='C' && t[2]<='C') || (s[2]>='D' && t[2]>='D')){
        x=s[2]-'A';
        y=t[2]-'A';
        x+=(x==3);
        y+=(y==3);
        if(abs(y-x)==1){
            cout << "1111";
        }else{
            cout << "1110";
        }
    }else{
        cout << "1100";
    }
}
