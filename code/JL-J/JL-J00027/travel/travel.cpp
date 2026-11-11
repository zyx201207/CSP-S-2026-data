#include<iostream>
#include<string>
using namespace std;

bool same_col(char c1,char c2){
    int c1pos=0,c2pos=0;
    if(c1=='A'||c1=='B'||c1=='C')c1pos=0;
    else c1pos=1;
    if(c2=='A'||c2=='B'||c2=='C')c2pos=0;
    else c2pos=1;
    if(c1pos==c2pos)return true;
    return false;
}

bool is_nearby(char c1,char c2){
    if(same_col(c1,c2)){
        return (c1-c2==1||c2-c1==1);
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int car1,car2;
    string seat1,seat2;
    cin>>car1>>seat1>>car2>>seat2;
    if(car1==car2){
        cout<<"1";
        if(seat1[0]==seat2[0]&&seat1[1]==seat2[1]){
            cout<<"1";
            char col1=seat1[2];
            char col2=seat2[2];
            if(same_col(col1,col2)){
                cout<<"1";
                if(is_nearby(col1,col2)){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
