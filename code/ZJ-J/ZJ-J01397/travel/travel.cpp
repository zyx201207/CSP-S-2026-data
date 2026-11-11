#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if (s1!=s3){
        printf("0000\n");
        return 0;
    }
    printf("1");
    if (s2[0]!=s4[0]||s2[1]!=s4[1]){
        printf("000\n");
        return 0;
    }
    int ch1=s2[2]-'A'+1,ch2=s4[2]-'A'+1;
    if (ch1==6)ch1=5;
    if (ch2==6)ch2=5;
    printf("1");
    if (ch1<=3&&ch2>=4){
        printf("00\n");
        return 0;
    }
    if (ch2>=4&&ch1<=3){
        printf("00\n");
        return 0;
    }
    printf("1");
    if (abs(ch1-ch2)!=1){
        printf("0\n");
    }
    else printf("1\n");
    return 0;
}