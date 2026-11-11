#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int a,b;string a1,b1;
    int zwa,zwb;
    char z1,z2;
    string p1="0ABC",p2="0DF";
    string p3="0AB",p4="0BC";
    cin>>a>>a1>>b>>b1;
    zwa=(a1[0]-'0')*10+a1[1]-'0';
    zwb=(b1[0]-'0')*10+b1[1]-'0';
    z1=a1[2],z2=b1[2];
    //cout<<zwa<<' '<<zwb<<"\n"<<z1<<' '<<z2;
    bool aABC=false,aDF=false;
    bool bABC=false,bDF=false;
    bool aBC=false,bBC=false;
    bool aAB=false,bAB=false;
    for(int i=1;i<=3;i++){
        if(z1==p1[i]){
            aABC=true;
        }
        if(z2==p1[i]){
            bABC=true;
        }
    }
    for(int i=1;i<=2;i++){
        if(z1==p2[i]){
            aDF=true;
        }
        if(z2==p2[i]){
            bDF=true;
        }
    }

    for(int i=1;i<=2;i++){
        if(z1==p3[i]){
            aAB=true;
        }
        if(z2==p3[i]){
            bAB=true;
        }
    }
    for(int i=1;i<=2;i++){
        if(z1==p4[i]){
            aBC=true;
        }
        if(z2==p4[i]){
            bBC=true;
        }
    }

    if(a==b){
        cout<<"1";
        if(zwa==zwb){
            cout<<"1";
            if((aABC==true&&bABC==true)||(aDF==true&&bDF==true)){
                cout<<"1";
                if((aDF==true&&bDF==true)||(aAB==true&&bAB==true)||(aBC==true&&bBC==true)){
                    cout<<"1";
                    return 0;
                }
                else{
                    cout<<"0";
                    return 0;
                }
            }
            else{
                cout<<"00";
                return 0;
            }
        }
        else{
            cout<<"000";
            return 0;
        }
    }
    cout<<"0000";
    return 0;


}
