#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //check this before you submit!

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }

    string a=s1.substr(0,2),a1=s2.substr(0,2);
    if(a==a1){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }

    int b=s1[2]-'A',b1=s2[2]-'A';

    if((b>=0&&b<=2&&b1>=0&&b1<=2)||(b>=3&&b<=5&&b1>=3&&b1<=5)){
        cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }

    if((b==0&&b1==1)||(b==1&&b1==2)||(b==3&&b1==5)||
       (b1==0&&b==1)||(b1==1&&b==2)||(b1==3&&b==5)){
        cout<<1;
       }
    else{
        cout<<"0";
    }

    return 0;
}
