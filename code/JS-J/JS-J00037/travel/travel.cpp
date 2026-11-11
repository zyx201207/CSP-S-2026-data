#include<bits/stdc++.h>
using namespace std;
string a,b;
string an,bn;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>an>>b>>bn;
    char aa=an[2],bb=bn[2];
    if(a==b){
        cout<<1;
        for(int i=0;i<=1;i++){
            if(an[i]!=bn[i]){
                cout<<"000";
                return 0;
            }
        }
        cout<<1;
        if(aa<='C' && bb>='D' || aa>='D' && bb<='C'){
            cout<<"00";
            return 0;
        }
        cout<<1;
        if(aa==(bb+1) || bb==(aa+1)){
            cout<<1;
        }else{
            cout<<0;
        }
    }
    else {
        cout<<"0000";
        return 0;
    }
    return 0;
}
