#include<bits/stdc++.h>
using namespace std;
char s1[20],s2[20],se1,se2;
int a1,b1,a2,b2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a1>>s1>>a2>>s2;
    b1=(s1[0]-'0')*10+(s1[1]-'0');
    se1=s1[2]-'A'+1;
    b2=(s2[0]-'0')*10+(s2[1]-'0');
    se2=s2[2]-'A'+1;
    if(a1==a2){
        cout<<"1";
        if(b1==b2){
            cout<<"1";
            if((se1<=3&&se2<=3)||(se1>=4&&se1<=6&&se2>=4&&se2<=6)){
                cout<<"1";
                if(se1<=3&&se1>=0){
                    if(abs(se1-se2)==1){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
                }else{
                    if(abs(se1-se2)==2){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
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
