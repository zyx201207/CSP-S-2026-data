#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);  //记得及时解除注释！
    freopen("travel.out","w",stdout);  //记得及时解除注释！
    ios::sync_with_stdio(false);
    cin.tie(0);
    int rn1,rn2;
    string xn1,xn2,xn3,xn4;
    cin >> rn1 >> xn1 >> rn2 >> xn2; 
    xn3=xn1;xn3.pop_back();xn4=xn2;xn4.pop_back();
    
    //车厢
    if(rn1 == rn2){
        cout <<"1";
        if(xn3==xn4){
            cout<<"1";
            if((xn1[2]<='C' &&xn2[2]<='C') || (xn1[2]>'C' &&xn2[2]>'C'))
            {
                cout<<"1";
                if(xn1[2]==xn2[2]+1 || xn2[2]==xn1[2]+1){
                   cout<<"1";
                }else cout<<"0";
            }else cout<<"00";
        }else cout<<"000";
    }else cout<<"0000";

    return 0;
}