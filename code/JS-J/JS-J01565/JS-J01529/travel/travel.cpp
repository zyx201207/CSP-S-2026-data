#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1 ,c2 ,s2;
int x1,x2,x3,x4;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0] == '0'){
        x1 = c1[1] - '0';
    }else{
        x1 = (c1[0] - '0')*10 + (c1[1] - '0');
    }
    if(c2[0] == '0'){
        x2 = c2[1] - '0';
    }else{
        x2= (c2[0] - '0')*10 + (c2[1] - '0');
    }
    if(x1 == x2){
        cout<<"1";
    }else{
        cout<<"0000";
        return 0;
    }


    if(s1[0] == '0'){
        x3 = s1[1] - '0';
    }else{
        x3 = (s1[0] - '0')*10 + (s1[1] - '0');
    }
    if(s2[0] == '0'){
        x4 = s2[1] - '0';
    }else{
        x4= (s2[0] - '0')*10 + (s2[1] - '0');
    }
    if(x3 == x4){
        cout<<"1";
    }else{
        cout<<"000";
        return 0;
    }

    if((s1[2] == 'A'&&s2[2] == 'B')||(s1[2] == 'A'&&s2[2] == 'C')||(s1[2] == 'B'&&s2[2] == 'C')||(s1[2] == 'B'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'B')||(s1[2] == 'D'&&s2[2] == 'F')||(s1[2] == 'F'&&s2[2] == 'D')){
        cout<<"1";
    }else{
        cout<<"00";
        return 0;
    }

    if((s1[2] == 'A'&&s2[2] == 'B')||(s1[2] == 'B'&&s2[2] == 'C')||(s1[2] == 'B'&&s2[2] == 'A')||(s1[2] == 'C'&&s2[2] == 'B')||(s1[2] == 'D'&&s2[2] == 'F')||(s1[2] == 'F'&&s2[2] == 'D')){
        cout<<"1";
    }else{
        cout<<"0";
    }
    return 0;
}
