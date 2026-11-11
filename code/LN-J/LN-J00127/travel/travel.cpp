#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x_che,r_che;
    string x_zuo,r_zuo;
    bool yes[5]={false};
    cin>>x_che>>x_zuo>>r_che>>r_zuo;
    bool is_1=false;
    if(x_che==r_che){
    	is_1=true;
        yes[1]=true;
    }
    bool is_2=false;
    if(x_zuo[0]==r_zuo[0]&&x_zuo[1]==r_zuo[1]&&is_1){
        yes[2]=true;
        is_2=true;
    }
    bool x_wei=false,r_wei=false;
    if(x_zuo[2]=='A'||x_zuo[2]=='B'||x_zuo[2]=='C'){
        x_wei=true;
    }
    if(r_zuo[2]=='A'||r_zuo[2]=='B'||r_zuo[2]=='C'){
        r_wei=true;
    }
    bool is_3=false;
    if(r_wei==x_wei&&is_2){
        yes[3]=true;
        is_3=true;
    }
    if(r_zuo[2]-'A'==x_zuo[2]-'A'+1||r_zuo[2]-'A'==x_zuo[2]-'A'-1){
        if(is_3){
            yes[4]=true;
        }
    }
    for(int i=1;i<=4;i++){
        cout<<yes[i];
    }
    return 0;
}
