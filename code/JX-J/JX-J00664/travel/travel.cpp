#include<bits/stdc++.h>
using namespace std;
int c1,c2,k1,k2;
string s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.in","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    k1=s1[2]-64;
    k2=s2[2]-64;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<"1";
            if(k1<4&&k2<4||k1>3&&k2>3){
                cout<<"1";
                if(abs(k1-k2)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
