#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        if(s1[1]!=s2[1]||s1[0]!=s2[0]){
            cout<<"1000";
            return 0;
        }
        else {
            char a1=s1[2];
            char b1=s2[2];
            if(!((a1>'C'&&b1>'C')||(a1<='C'&&b1<='C'))){
                cout<<"1100";
                return 0;
            }
            else{
                if(a1+1==b1||b1+1==a1){
                    cout<<"1111";
                    return 0;
                }
                else{
                    cout<<"1110";
                }
            }
        }
    }
    return 0;
}
