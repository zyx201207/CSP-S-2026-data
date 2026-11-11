#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<"1";
        char tp1=s1[0];
        char tp2=s1[1];
        char tp3=s1[2];

        char pt1=s2[0];
        char pt2=s2[1];
        char pt3=s2[2];
        if((tp1!=pt1)||(tp2!=pt2)){
            cout<<"000";
        }else{
            cout<<"1";
            if(tp3>='D'&&pt3>='D'){
                cout<<"11";
            }
            else if(tp3<='C'&&pt3<='C'){
                cout<<"1";
                if(abs(tp3-pt3)==1)cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
    }

}
