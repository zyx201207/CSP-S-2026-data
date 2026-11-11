#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,a1,a2;
int b1,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    a1=s1[0]+s1[1];
    a2=s2[0]+s2[1];
    b1=s1[2]-'A';
    b2=s2[2]-'A';
    if(c1==c2){
        cout<<"1";
        if(a1==a2){
            cout<<"1";
            if((b1<3&&b2<3||(b1>=3&&b2>=3))){
                cout<<"1";
                if(abs(b1-b2)==1||(b1+b2==8)){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
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
