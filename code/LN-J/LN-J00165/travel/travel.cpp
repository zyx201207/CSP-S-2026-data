#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool check=true;
bool f1(){
    if(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'){
        return true;
    }
    else if((a2[2]=='D'||a2[2]=='F')&&(b2[2]=='D'||b2[2]=='F')){
        return true;
    }
    return false;
}
bool f2(){
    if((a2[2]+1==b2[2])||(a2[2]-1==b2[2])){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a1>>a2>>b1>>b2;
    if(a1[0]==b1[0]&&a1[1]==b1[1]){
        cout<<"1";
        if(a2[0]==b2[0]&&a2[1]==b2[1]){
            cout<<"1";
            if(f1()){
                cout<<"1";
                if(f2()){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }else{
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
