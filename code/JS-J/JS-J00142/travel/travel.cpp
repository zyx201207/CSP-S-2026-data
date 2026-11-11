#include<bits/stdc++.h>
using namespace std;
string cone,sone,ctwo,stwo,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>cone>>sone>>ctwo>>stwo;
    if(cone==ctwo){
        ans+='1';
        if(sone[0]==stwo[0]&&sone[1]==stwo[1]){
            ans+='1';
            int theone,thetwo;
            theone=sone[2]-'A'+1;
            thetwo=stwo[2]-'A'+1;
            if((theone<=3&&thetwo<=3)==1||(theone>3&&thetwo>3)==1){
                ans+='1';
                if(theone-thetwo==1||thetwo-theone==1){
                    ans+='1';
                }else{
                    ans+='0';
                }
            }else{
                ans+="00";
            }
        }else{
            ans+="000";
        }
    }else{
        ans+="0000";
    }
    cout<<ans;
    return 0;
}
