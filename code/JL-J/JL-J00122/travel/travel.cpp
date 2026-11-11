#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1.substr(0,2)==s2.substr(0,2)){
            cout<<"1";
            char n=s1[s1.size()-1],m=s2[s2.size()-1];
            if((n>='A' && n<='C' && m>='A' && m<='C') || (n=='D' && m=='F') || (n=='F' && m=='D')){
                cout<<"1";
                if(n>='A' && n<='C' && m>='A' && m<='C'){
                    if(abs(int(n)-int(m))==1){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else if((n=='D' && m=='F') || (m=='D' && n=='F')){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
