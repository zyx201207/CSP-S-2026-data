#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string rx;
    int xrc,xxc;
    int xrp,xxp;
    char xrz,xxz;
    int xrzx,xxzx;
    cin>>xrc>>xrp;
    cin>>xrz;
    cin>>xxc>>xxp;
    cin>>xxz;
    xrzx=int(xrz-'A'+1);
    xxzx=int(xxz-'A'+1);
    if(xrc==xxc){
        if(xrp==xxp){
            if((xrzx>=1&&xrzx<=3&&xxzx>=1&&xxzx<=3)||(xrzx>=4&&xrzx<=5&&xxzx>=4&&xxzx<=5)){
                    if(!((xrzx==4&&xxzx==3)||(xrzx==3&&xxzx==4))&&(max(xrzx,xxzx)-min(xrzx,xxzx)==1)){
                        rx+='1';
                        rx+='1';
                        rx+='1';
                        rx+='1';

                    }
                    else{
                        rx+='1';
                        rx+='1';
                        rx+='1';
                        rx+='0';
                    }
            }
            else{
                rx+='1';
                rx+='1';
                rx+='0';
                rx+='0';
            }
        }
        else{
            rx+='1';
            rx+='0';
            rx+='0';
            rx+='0';
        }
    }
    else{
        rx+='0';
        rx+='0';
        rx+='0';
        rx+='0';
    }
    cout<<rx;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
