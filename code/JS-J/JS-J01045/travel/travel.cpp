#include<bits/stdc++.h>
using namespace std;
string s1,b1,s2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>b1>>s2>>b2;
    if(s1==s2){
        cout<<1;
        if(b1[0]==b2[0]&&b1[1]==b2[1]){
            cout<<1;
            if((b1[2]<='C'&&b2[2]<='C')||(b1[2]>='D'&&b2[2]>='D')){
                cout<<1;
                if(abs(int(b1[2]-b2[2]))==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
        }
    return 0;
}
