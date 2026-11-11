#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,d1,d2;
    cin>>c1>>c2>>d1>>d2;
    if(c1==d1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    int flag=1;
    for(int i=0;i<=1;i++){
        if(c2[i]!=d2[i]){
            flag=0;
        }
    }
    if(c1==d1&&flag==1){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    int f=0;
    if(c1==d1&&flag==1&&(c2[2]>='A'&&c2[2]<='C'&&d2[2]<='C'&&d2[2]>='A')||(c2[2]>='D'&&c2[2]<='F'&&d2[2]>='D'&&d2[2]<='F')){
        cout<<"1";
        f=1;
    }
    else{
        cout<<"0";
    }
    if(c1==d1&&flag==1&&f==1&&(d2[2]==c2[2]+1||c2[2]==d2[2]+1)){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
    return 0;
}
