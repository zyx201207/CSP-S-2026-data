#include<bits/stdc++.h>
using namespace std;
int sc[5]{0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("treval.out","w",stdout);
    int cx1,cx2;
    string zw1,zw2;
    cin>>cx1>>zw1>>cx2>>zw2;
    if(cx1==cx2){
        sc[1]=1;
        if(zw1[0]==zw2[0]&&zw1[1]==zw2[1]){
            sc[2]=1;
            if(zw1[2]<='C'&&zw2[2]<='C'){
                sc[3]=1;
                if(zw1[2]=='B'||zw2[2]=='B'){
                    sc[4]=1;
                }
            }
            else if(zw1[2]>='C'&&zw2[2]>='C'){
                sc[3]=1;
                sc[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<sc[i];
    }
    return 0;
}
