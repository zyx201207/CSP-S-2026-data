#include<iostream>
#include<cmath>
using namespace std;
string c1,s1,c2,s2;
int f1=0,f2=0,f3=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){//是否在同一节车厢
        cout<<1;
        f1=1;
    }else{
        cout<<0;
    }
    if(s1[0]==s2[0] && s1[1]==s2[1]){//是否在同一节车厢的同一排
        cout<<1;
        f2=1;
    }else{
        cout<<0;
    }
    if(f1==1 && f2==1){
        if(s1[2]=='A'){
            if(s2[2]=='B' || s2[2]=='C'){
                cout<<1;
                f3=1;
            }else{
                cout<<0;
            }
        }else if(s1[2]=='B'){
            if(s2[2]=='A' || s2[2]=='C'){
                cout<<1;
                f3=1;
            }else{
                cout<<0;
            }
        }else if(s1[2]=='C'){
            if(s2[2]=='A' || s2[2]=='B'){
                cout<<1;
                f3=1;
            }else{
                cout<<0;
            }
        }else if(s1[2]=='D'){
            if(s2[2]=='F'){
                cout<<1;
                f3=1;
            }else{
                cout<<0;
            }
        }else if(s1[2]=='F'){
            if(s2[2]=='D'){
                cout<<1;
                f3=1;
            }else{
                cout<<0;
            }
        }
    }else{
        cout<<0;
    }
    if(f1==1 && f2==1 && f3==1 && abs(int(s1[2])-int(s2[2]))==1){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}
