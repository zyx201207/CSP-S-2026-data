#include<bits/stdc++.h>
using namespace std;
char c11,c12,C13,s11,s12,s13,S14,c21,c22,C23,s21,s22,s23;
int a[5],z1,z2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%c%c %c%c%c %c%c %c%c%c",&c11,&c12,&s11,&s12,&s13,&c21,&c22,&s21,&s22,&s23);
    if(s13=='D'||s13=='F') z1=1;
    if(s23=='D'||s23=='F') z2=1;
    if(c11==c21&&c12==c22){
       a[1]=1;
       if(s11==s21&&s12==s22){
           a[2]=1;
           if(z1==z2){
              a[3]=1;
              if(z1==1) a[4]=1;
              else{
                  if(s13=='B'||s23=='B') a[4]=1;
              }
           }
       }
    }
    printf("%d%d%d%d",a[1],a[2],a[3],a[4]);
    return 0;
}
