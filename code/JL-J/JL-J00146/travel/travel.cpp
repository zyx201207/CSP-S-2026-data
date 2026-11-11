#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
    }else{
        cout<<"0";

    }
    if(b[0]==d[0]&&b[1]==d[1]&&a==c){

            cout<<"1";


    }else{
        cout<<"0";

    }
    if(b[2]-d[2]<=3&&b[2]-d[2]>=-3){
        if(a==c){
            if(b[0]==d[0]&&b[1]==d[1]){
                cout<<"1";
            }

        }else{
            cout<<"0";
        }

    }else{
        cout<<"0";

    }
    if(b[2]-d[2]<=1&&b[2]-d[2]>=-1){
        if(a==c){
            if(b[0]==d[0]&&b[1]==d[1]){
                    if(b[2]-d[2]<=3&&b[2]-d[2]>=-3)
                        cout<<"1";
            }
        }else{
            cout<<"0";
        }
    }else{
        cout<<"0";
    }

    return 0;
}
