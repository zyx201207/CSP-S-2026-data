#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1,a2,b2;
char a3,b3;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>a >>a1 >>b >>b1;
    a2=a1[0]+a1[1];
    b2=b1[0]+b1[1];
    a3=a1[2];
    b3=b1[2];
    //cout << a2 <<" "<<a3 <<endl;
    //cout << b2 <<" "<<b3<<endl;
    if(a!=b){
        cout <<"0000";
        return 0;
    }else cout << 1;
    if(a2==b2){
        cout << 1;
    }else{
        cout <<"000";
        return 0;
    }
    //if((a3+1==b3 || b3+1==a3)&&((a3<='c'&&b3<='c')||(a3>'c'&&b3>'c')))
    if((a3>'C'&& b3>'C')||(a3<='C'&&b3<='C'))cout <<1;
    else{
        cout << "00";
        return 0;
    }
    if(a3+1==b3 || b3+1==a3)cout <<1;
    else cout <<0;
    return 0;
}
