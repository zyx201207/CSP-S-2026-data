#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    int d2,d4;
    if(c2[2]<='C' && c2[2]>='A'){
        d2=1;
    }else{
        d2=2;
    }
    if(c4[2]<='C' && c4[2]>='A'){
        d4=1;
    }else{
        d4=2;
    }
    bool f1,f2,f3,f4;
    if(c1==c3){
        f1=1;
        if(c2[0]==c4[0] && c2[1]==c4[1]){
            f2=1;
            if(d2==d4){
                f3=1;
                if(d2==2){
                    f4=1;
                }else if(c2[2]=='B' || c4[2]=='B'){
                    f4=1;
                }else{
                    f4=0;
                }
            }else{
                f3=f4=0;
            }
        }else{
            f2=f3=f4=0;
        }
    }else{
        f1=f2=f3=f4=0;
    }
    cout<<f1<<f2<<f3<<f4;
    return 0;
}
