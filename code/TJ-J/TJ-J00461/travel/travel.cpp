#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2 = "";
    cin>>c1>>s1>>c2>>s2;
    string seat1="";
    string seat2="";
    string row1[2];
    string row2[2];
    int a1,a2,a3,a4 = 0;
    for(int i = 0;i<3;i++){
        if (i==0){
            row1[0]=s1[0];
            row1[1]=s1[1];
            row2[0]=s2[0];
            row2[1]=s2[1];
        }
        else if(i==2){
            seat1 = s1[2];
            seat2 = s2[2];
        }
    }
    if (c1==c2){
        a1 = 1;
    }
    if(a1 && row1[0] == row2[0] &&row1[1]==row2[1]){
        a2=1;
    }
    if(a2 && (((seat1=="A"||seat1=="B"||seat1 =="C")&&(seat2=="A"||seat2=="B"||seat2 == "C"))||((seat1=="D"||seat1 == "F")&&(seat2=="D"||seat2=="F")))){
        a3=1;
    }
    if(a3 && ((seat1=="A"&&seat2=="B")||(seat1=="B" && seat2=="A"))||((seat1=="B"&&seat2=="C")||(seat1=="C" && seat2=="B"))||((seat1=="D"&&seat2=="F")||(seat1=="F" && seat2=="D"))){
        a4 = 1;
    }
    cout<<a1<<" "<<a2<<" "<<a3<<" "<<a4;
    return 0;
    
}
