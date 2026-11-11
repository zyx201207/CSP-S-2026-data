#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1!=c2) printf("0000");
    else{
        printf("1");
        int num1=(s1[0]-'0')*10+(s1[1]-'0');
        int num2=(s2[0]-'0')*10+(s2[1]-'0');
        if (num1!=num2) printf("000");
        else{
            printf("1");
            int p1=s1[2]-'A',p2=s2[2]-'A';
            if ((p1<3 && p2<3) || (p1>2 && p2>2)){
                printf("1");
                if (abs(p1-p2)==1) printf("1");
                else printf("0");
            }
            else printf("00");
        }
    }
    return 0;
}
