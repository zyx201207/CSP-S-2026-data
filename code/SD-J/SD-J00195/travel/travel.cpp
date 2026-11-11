#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>

#define ll long long
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;
    int car1=(c1[0]-'0')*10+(c1[1]-'0');
    int car2=(c2[0]-'0')*10+(c2[1]-'0');
    int lin1=(s1[0]-'0')*10+(s1[1]-'0');
    int lin2=(s2[0]-'0')*10+(s2[1]-'0');
    int num1=s1[2]-'A'+1;
    int num2=s2[2]-'A'+1;
    if(car1!=car2){
        cout<<"0000";
        return 0;
    }
    cout<<'1';
    if(lin1!=lin2){
        cout<<"000";
        return 0;
    }
    cout<<'1';
    if(!(((num1<=3)&&(num2<=3))||((num1>=4)&&(num2>=4)))){
        cout<<"00";
        return 0;
    }
    cout<<'1';
    if(num1<=3){
        if(max(num1,num2)-min(num1,num2)==1){
            cout<<'1';
            return 0;
        }
        cout<<'0';
    } else{
        if(max(num1,num2)-min(num1,num2)==2){
            cout<<'1';
            return 0;
        }
        cout<<'0';
    }
    return 0;
}
