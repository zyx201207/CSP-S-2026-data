#include <bits/stdc++.h>
using namespace std;

string row_r,row_x;
string sit_r,sit_x;

int check1(string x,string y){
    if((x=="A"||x=="B"||x=="C")&&(y=="A"||y=="B"||y=="C")){
        return 1;
    }
    if((x=="D"||x=="E")&&(y=="D"||y=="E")){
        return 1;
    }
    return 0;
}

int check2(string x,string y){
    if(check1(x,y)==0){
        return 0;
    }
    if((x=="A"&&y=="B")||(x=="B"&&y=="A")||(x=="B"&&y=="C")||(x=="C"&&y=="B")||(x=="D"&&y=="E")||(x=="E"&&y=="D")){
        return 1;
    }
    return 0;
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;

    row_r = c2[0] + c2[1],row_x= c4[0]+ c4[1];
    sit_r = c2[2] , sit_x = c4[2];

    if(c1==c3){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }

    if(row_x==row_r){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }

    cout<<check1(sit_r,sit_x)<<check2(sit_r,sit_x)<<endl;
    return 0;
}