#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,l1,l2;
char k1,k2;
int flag[5]={0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;i++){
        l1+=s1[i];
        l2+=s2[i];
    }
    k1=s1[2];
    k2=s2[2];
    if(c1==c2){
        flag[1]=1;
        if(l1==l2){
            flag[2]=1;
            if((k1<='C'&&k2<='C')||(k1>='D'&&k2>='D')){
                flag[3]=1;
                if(abs(k1-k2)==1||(k1=='D'&&k2=='F')||(k2=='D'&&k1=='F')){
                    flag[4]=1;
                }
            }
        }
    }
    for(int i=1;i<=4;i++){
        cout<<flag[i];
    }
    return 0;
}
