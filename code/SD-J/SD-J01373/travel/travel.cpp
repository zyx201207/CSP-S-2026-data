#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.ans","r",stdout);
char aa,ab,ac,ad,af,ba,bb,bc,bd,bf;
cin>>aa>>ab>>ac>>ad>>af>>ba>>bb>>bc>>bd>>bf;
if(aa==ba&&ab==bb){
cout<<"1";
if(ac==bc&&ad==bd){
cout<<"1";
if(((af=='a'||af=='b'||af=='c')&&(bf=='a'||bf=='b'||bf=='c'))||((af=='d'||af=='f')&&(bf=='d'||bf=='f'))){
cout<<"1";
if(ad+1==bd||ad-1==bd||af+1==bf||af-1==bf||bd+1==ad||bd-1==ad||bf+1==af||bf-1==af){
cout<<"1";
}else{
cout<<"0";
}
}else{
cout<<"00";
}
}else{
cout<<"000";
}
}else{
cout<<"0000";
}
return 0;
}
