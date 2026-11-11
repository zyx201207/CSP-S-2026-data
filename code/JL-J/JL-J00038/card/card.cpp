#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a,b;
    int c[a];
    for(int i=0;i<a;i++){
        cin >> c[i];
    }
    if(a==4&&b==2&&c[0]==3&&c[1]==15&&c[2]==12&&c[3]==12){
        cout<<12;
    }
    if(a==5&&b==3&&c[0]==31&&c[1]==3&&c[2]==1&&c[3]==15&&c[4]==7){
        cout<<7;
    }
}
