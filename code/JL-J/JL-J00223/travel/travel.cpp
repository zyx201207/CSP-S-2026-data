#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c,d;
    int c_1,c_3,a,b;
    string c_2,c_4;
    cin>>c_1>>c_2>>c_3>>c_4;
    if(c_1!=c_3){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    a=(c_2[0]-'0')*10+c_2[1];
    b=(c_4[0]-'0')*10+c_4[1];
    if(a!=b){
        cout<<"000";
        return 0;
    }
    cout<<1;
    if((c_2[2]-'A'<=2&&c_4[2]-'A'<=2)||(c_2[2]-'A'>2&&c_4[2]-'A'>2&&(c_2[2]-'A'<=4&&c_4[2]-'A'<=4))){
        cout<<1;
        if(abs((int)(c_2[2]-c_4[2]))==1){
            cout<<1;
        }else{
            cout<<0;
        }
    }else{
        cout<<"00";
    }
    return 0;
}
