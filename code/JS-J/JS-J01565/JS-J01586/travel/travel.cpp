#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
        string e="",f="";
        for(int i=0;i<2;i++){
            e=e+b[i];
            f=f+d[i];
        }
        if(e==f){
            cout<<1;
             if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
                cout<<1;
                if(b[2]==d[2]+1||d[2]==b[2]+1){
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
