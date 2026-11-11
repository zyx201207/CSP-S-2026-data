#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,b1;
    string a2,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1 == b1){
        cout<<'1';
    }else{
        cout<<"0000";
        return 0;
    }
    int f = 0;
    for(int i = 0;i < 2;i++){
        if(a2[i] != b2[i]){
            f = 1;
        }
    }if(f == 1){
        cout<<"000";
        return 0;
    }else{
        cout<<'1';
    }
    char a = a2[2],b = b2[2];
    if((a == 'D' && b == 'F') || (a == 'F' && b == 'D')){
        cout<<"11";
        return 0;
    }
    if((a >= 'D' && b <= 'C') || (a <= 'C' && b >= 'D')){
        cout<<"00";
        return 0;
    }else{
        cout<<"1";
        if(a + 1 == b || b + 1 == a){
            cout<<"1";
        }
        else{
            cout<<"0";
        }
    }
    return 0;
}
