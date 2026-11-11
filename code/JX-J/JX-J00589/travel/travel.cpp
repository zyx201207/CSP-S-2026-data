#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3&&c1!="01"&&c3!="16"){
        cout<<'1';
        if((int(c2[0])+int(c2[1]))==(int(c4[0])+int(c4[1]))){
            cout<<'1';
            if((c2[2]-'A'<=2)&&(c4[2]-'A'>2)||(c4[2]-'A'<=2)&&(c2[2]-'A'>2)){
                cout<<"00";
            }
            else{
                cout<<'1';
                if(abs((c2[2]-'0')-(c4[2]-'0'))==1){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
