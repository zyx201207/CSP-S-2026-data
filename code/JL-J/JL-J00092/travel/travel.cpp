//#include<bits/c++.h>
#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //ios.sync_with_stdio(false);
    //cin.tie(0);
    char c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        if(abs(s1-s2)<=5&&s1-s2!=0){
            cout<<1;
            if(abs(s1-s2)<=3&&s1-s2!=0){
                cout<<1;
                if(abs(s1-s2)==0){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0;
            }
        }else{
        cout<<0;
        }
    }else{
        cout<<0;
    }

    return 0;
}
