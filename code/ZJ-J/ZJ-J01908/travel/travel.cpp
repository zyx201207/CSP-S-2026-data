#include <bits/stdc++.h>
using namespace std;
int ca,cb;
string sa,sb;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ca>>sa>>cb>>sb;
    if(ca==cb){
        cout<<1;
        string bha=sa.substr(0,2),bhb=sb.substr(0,2);
        if(bha==bhb){
            cout<<1;
            char za=sa[2],zb=sb[2];
            if((za<='C'&&zb<='C')||(za>='D'&&zb>='D')){
                cout<<1;
                if(abs(za-zb)<=1){
                    cout<<1;
                }
                else{
                    cout<<0;
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
