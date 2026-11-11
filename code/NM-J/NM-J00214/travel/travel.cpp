#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int car1[2],car2[2];
int se1[3],se2[3];
bool flag[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for(int i=0;i<4;++i) flag[i]=1;
    cin>>c1>>s1>>c2>>s2;
    for(int i=0;i<2;++i){
        car1[i]=c1[i]-'0';
        car2[i]=c2[i]-'0';
        if(car1[i]!=car2[i]){
            flag[0]=0;
            break;
        }
    }
    if(!flag[0]) cout<<"0000";
    else{
        for(int i=0;i<2;++i){
            se1[i]=s1[i]-'0';
            se2[i]=s2[i]-'0';
            if(se1[i]!=se2[i]) flag[1]=0;
        }
        if(!flag[1]) cout<<"1000";
        else{
            se1[2]=s1[2]-'A';
            se2[2]=s2[2]-'A';
            if(se1[2]>=0&&se1[2]<=2){
                if(se2[2]>2) cout<<"1100";
                else{
                    if(abs(se1[2]-se2[2])==1) cout<<"1111";
                    else cout<<"1110";
                }
            }
            else{
                if(se2[2]<=2) cout<<"1100";
                else cout<<"1111";
            }

        }
    }
    return 0;
}
