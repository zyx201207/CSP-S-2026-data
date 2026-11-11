#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
bool check(char x,char y){
    if(x<='C' && y<='C' || x>='D' && y>='D') return 1;
    else return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>a1>>b1;
    if(a==a1){
        if(b[0]==b1[0] && b[1]==b1[1]){
                if(check(b[2],b1[2])){
                    if(abs(b[2]-b1[2])==1) cout<<"1111";
                    else cout<<"1110";
                }else cout<<"1100";
        }else cout<<"1000";
    }else cout<<"0000";
    return 0;
}
