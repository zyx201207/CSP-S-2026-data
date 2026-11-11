#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
        cout<<"1";
    }else {
        cout<<"000";
        return 0;
    }
    if((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>=3&&s2[2]-'A'>=3)){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }
    if(abs(s1[2]-s2[2])==1){
        cout<<"1";
    }else{
        cout<<"0";
    }
	return 0;
}
//cspjs_2026 while(true)rp+=LLONG_MAX;
//
//
//08:45 finish T1
//09:12 finish T2
//09:36 T3 so diffcuilt
//09:46 give up T3 55555555
//10:40 T4 difficult too... only 24pts for #1~#6
//11:00 restart T3
//11:29 I finish T3!!!!!!
//11:45 unable to ak cspj,,,
//in grade 9 and im still so weak/bx/bx
//Never gonna give you up~
