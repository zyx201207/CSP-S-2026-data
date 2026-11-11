#include</stdc++.h>
using namespace std;
string zf[10];
int l,k[10],pd;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=1;i<=4;i++){
        cin>>zf[i];
    }
    for(int j=0;j<=zf[1].size();j++){
        if(zf[1][j]!=zf[3][j]){
            pd=1;
            break;
        }
    }
    if(pd==1){
        cout<<"0000";
    }
    else{
        for(int i=0;i<=zf[2].size();i++){
            if(zf[2][i]>='0' && zf[2][i]<='9'){
                if(zf[2][i]!=zf[4][i]){
                    cout<<"1000";
                    return 0;
                }
            }
            else{
                if(zf[2][i]<="C"){
                    if(zf[4][i]<="C"){
                        if(abs(zf[2][i]-zf[4][i])==1)cout<<"1111";
                        else cout<<"1110";
                    }
                    else cout<<"1100";
                }
                else {
                    if(zf[4][i]>="D"{
                        if(abs(zf[2][i]-zf[4][i])==1)cout<<"1111";
                        else cout<<"1110";
                    }
                    else cout<<"1100";
                }
                return 0;
            }


        }
    }

    return 0;
}
