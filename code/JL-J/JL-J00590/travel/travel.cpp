#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

char a1,a2,b1,b2,a3,a4,b3,b4;
char a5,b5;
cin >> a1 >> a2 >> a3 >> a4 >> a5 >> b1 >> b2 >> b3 >> b4 >> b5;
int c1 = (a1 - '0' + 1)*10+a2,c2 = (b1 - '0' + 1)* 10 + b2;
if(c1 == c2){
    cout << 1;
}else {
    cout << "0000";
    return 0;
}
int a = (a3 - '0' + 1)*10+a4,b=(b3 - '0' + 1)* 10 + b4;
if(a == b){
    cout << 1;
}else{
    cout << "000";
    return 0;
}
int x = (a5 - 'A' + 1),y = (b5 - 'A' + 1);
if(x<=3&&y<= 3){
    cout << 1;
}else if(x>=4&&y >=4){
    cout << 1;
}else{
    cout << "00";
    return 0;
}
if(x==1&&y == 3){
    cout << 0;
    return 0;
}else if(x==3 && y == 1){
    cout << 0;
    return 0;
}
cout << 1;
return 0;
}
