#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int a=(c1[0]-'0')*10+(c1[1]-'0'),b=(s1[0]-'0')*10+(s1[1]-'0'),c=(c2[0]-'0')+(c2[1]-'0'),d=(s2[0]-'0')*10+(s2[1]-'0');
    int e=(s1[2]-'A'),f=(s2[2]-'A');
    if(a==c){
        cout<<1;
        if(b==d){
            cout<<1;
            if((e<=2&&f<=2)||(e>2&&f>2)){
                cout<<1;
                if(abs(e-f)==1){
                    cout<<1;
                }else  cout<<0;
            }else  cout<<"00";
        }else{
            cout<<"000";
        }
    }else  cout<<"0000";
    return 0;
}
