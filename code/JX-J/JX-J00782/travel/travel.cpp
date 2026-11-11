#include<bits/stdc++.h>
using namespace std;

int g[5]={1,1,1,2,2};

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c_R,c_X;
    string z_R,z_X;
    cin>>c_R>>z_R>>c_X>>z_X;

    if(c_R==c_X){
        cout<<"1";
        if(z_R[0]==z_X[0]&&z_R[1]==z_X[1]){
            cout<<"1";
            if(g[z_R[2]-'A']==g[z_X[2]-'A']){
                cout<<"1";
                if(abs(z_R[2]-z_X[2])==1){
                    cout<<"1";
                }else{
                    cout<<"0";
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
