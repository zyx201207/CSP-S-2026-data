#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int list[4]={0};

int main(){
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
freopen("travel.in","r",stdin);

freopen("travel.out","w",stdout);

    if(c1==c2){
        list[0]=1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            list[1]=1;
            if(int(s1[2])<=67 && int(s2[2])<=67){
                list[2]=1;
                if(int(s1[2])-int(s2[2])==1 || int(s2[2])-int(s1[2])==1){
                    list[3]=1;
                }
            }
            if(int(s1[2])>67 && int(s2[2])>67){
                list[2]=1;
                if(int(s1[2])-int(s2[2])==2 || int(s2[2])-int(s1[2])==2){
                    list[3]=1;
                }
            }
        }
    }
    for(int i = 0;i<4;i++){
        cout<<list[i];
    }
    //C==67;


return 0;
}
