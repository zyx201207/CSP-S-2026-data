#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long c1,c2,s1,s2;
    char z1,z2;
    cin>>c1>>s1>>z1>>c2>>s2>>z2;
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if(z1>='A' and z1<='C' and z2>='A' and z2<='C'){
                cout<<1;
                if(z1+1==z2 or z2+1==z1){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else if(z1>='D' and z1<='F' and z2>='D' and z2<='F'){
                cout<<11;
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
