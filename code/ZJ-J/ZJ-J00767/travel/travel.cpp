#include<bits/stdc++.h>
using namespace std;
int ax,bx;
string ay,by;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ax>>ay;
    cin>>bx>>by;
    if(ax==bx){
        cout<<1;
        int an=(ay[0]-'0')*10+(ay[1]-'0');
        int bn=(by[0]-'0')*10+(by[1]-'0');
        if(an==bn){
            cout<<1;
            char ac=ay[2],bc=by[2];
            if(ac>='A' && ac<='C' && bc>='A' && bc<='C'){
                cout<<1;
                if(ac==char((int)(bc)+1)){
                    cout<<1;
                }else if(ac==char((int)(bc)-1)){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else if(ac>='D' && ac<='F' && bc>='D' && bc<='F'){
                cout<<1;
                if(ac==char((int)(bc)+1)){
                    cout<<1;
                }else if(ac==char((int)(bc)-1)){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
