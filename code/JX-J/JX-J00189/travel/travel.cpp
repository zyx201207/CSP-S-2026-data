#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,a1,b,b1;
    cin>>a>>a1>>b>>b1;
    if(a[0]-'0'==b[0]-'0' and a[1]-'0'==b[1]-'0'){
        cout<<1;
        if((a1[0]-'0')*10+(a1[1]-'0')==(b1[0]-'0')*10+(b1[1]-'0')){
            cout<<1;
            if(a1[2]<='C' and b1[2]<='C' or a1[2]>'C' and b1[2]>'C'){
                cout<<1;
                if(abs(a1[2]-b1[2])==1){
                    cout<<1;
                }
                else{
                    cout<<"0";
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
