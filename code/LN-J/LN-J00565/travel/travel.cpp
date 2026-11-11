#include<bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    if(a==b){
        if(a1[0]==b1[0]&&a1[1]==b1[1]){
            if((a1[2]<'D'&&b1[2]<'D')||(a1[2]>'C'&&b1[2]>'C')){
                if(a1[2]-b1[2]==1||a1[2]-b1[2]==-1){
                    cout<<"1111";
                }else cout<<"1110";
            }else cout<<"1100";
        }else cout<<"1000";
    }else cout<<"0000";
    return 0;
}
