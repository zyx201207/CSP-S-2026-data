#include<bits/stdc++.h>
using namespace std;
void init(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    return;
}
bool ll(char a){
    if(a>='A' && a<='C'){
        return 0;
    }
    return 1;
}
int main(){
    init();
    string c1,c2,c3,c4,a="0000";
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        a[0]='1';
        if(c2[0]==c4[0] && c2[1]==c4[1]){
            a[1]='1';
            if(ll(c2[2])==ll(c4[2])){
                a[2]='1';
                if(abs(c2[2]-c4[2])==1){
                    a[3]='1';
                }
            }
        }
    }
    cout<<a<<endl;
}
