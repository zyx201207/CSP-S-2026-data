#include <bits/stdc++.h>
using namespace std;
int main(){
    /*freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);*/
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    char swod1,swod2;
    int cnum1 = 0,snum1 = 0,cnum2 = 0,snum2 = 0;
    cnum1 = (c1[0]-'0')*10+c1[1]-'0';
    snum1 = (s1[0]-'0')*10+s1[1]-'0';
    cnum2 = (c2[0]-'0')*10+c2[1]-'0';
    snum2 = (s2[0]-'0')*10+s2[1]-'0';
    swod1 = s1[2];
    swod2 = s2[2];
    if(swod1>swod2){
        swap(swod1,swod2);
    }
    if(cnum1==cnum2){
        cout<<'1';
        if(snum1==snum2){
            cout<<'1';
            if(swod1=='D'||swod2<='C'){
                cout<<'1';
                if(swod1==swod2-1){
                    cout<<'1';
                }
                else{
                    cout<<'0';
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
