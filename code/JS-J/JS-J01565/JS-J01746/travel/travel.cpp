#include <bits/stdc++.h>
using namespace std;
int r1,r2;
char s1[10],s2[10],s3[10],s4[10],c1,c2;
const string table="ABCDF";
bool diff(){
    for(int i=0;i<2;i++)
        if(s1[i]!=s3[i])
            return true;
    return false;
}
bool check1(){
    for(int i=0;i<3;i++)
        for(int j=3;j<5;j++)
            if(c1==table[i]&&c2==table[j])
                return false;
    for(int i=0;i<3;i++)
        for(int j=3;j<5;j++)
            if(c2==table[i]&&c1==table[j])
                return false;
    return true;
}
bool check2(){
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(c1==table[i]&&c2==table[j]
               &&(i<=2&&j<=2||i>=3&&j>=3)&&abs(i-j)==1)
               return true;
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s%s%s%s",s1,s2,s3,s4);
    if(diff())
        printf("0000");
    else{
        printf("1");
        sscanf(s2,"%d%c",&r1,&c1);
        sscanf(s4,"%d%c",&r2,&c2);
        if(s2[0]!=s4[0]||s2[1]!=s4[1])
            printf("000");
        else{
            printf("1");
            if(check1()){
                    printf("1");
                if(check2())
                    printf("1");
                else
                    printf("0");
            }else
                printf("00");
        }
    }
    return 0;
}
