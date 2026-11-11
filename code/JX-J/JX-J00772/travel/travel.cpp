#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,a1,a2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s2[1]==s1[1]){
            cout<<"1";
            if(s1[2]>='A'&&s1[2]<='c'&&s2[2]>='A'&&s2[2]<='C'
            ||s1[2]>='D'&&s1[2]<='E'&&s2[2]>='D'&&s2[2]<='E'){
                cout<<"1";
                if(abs(s1[2]-s2[2])==1){
                    cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";
    return 0;
}
