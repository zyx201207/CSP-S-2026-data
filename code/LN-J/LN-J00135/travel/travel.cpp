#include<bits/stdc++.h>
using namespace std;
char c1[7],c2[7];
char s1[7],s2[7];
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
if(c1[1]==c2[1]&&c1[2]==c2[2]){
printf("1");
}else{
printf("0000");
return 0;
}
if(s1[1]==s2[1]&&s2[2]==s1[2]){
printf("1");
}else{
printf("000");
return 0;
}
int x,y;
if(s1[3]=='A'||s1[3]=='C'||s1[3]=='B'){
x=1;
}else{
x=2;
}
if(s2[3]=='A'||s2[3]=='C'||s2[3]=='B'){
y=1;
}else{
y=2;
}
if(x==y){
printf("1");
}else{
printf("00");
return 0;
}
if(abs(s1[3]-s2[3])==1){
printf("1");
}else{
printf("0");
}
return 0;
}
