#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,c1,c2;
    int a33=0,b33=0,a11=0,a22=0,b11=0,b22=0;
    cin>>s1>>s2>>c1>>c2;
    a11=a11+10*(s1[0]-'0');
    a11=a11+(s1[1]-'0');


    b11=b11+10*(c1[0]-'0');
    b11=b11+(c1[1]-'0');
    if (b11 == a11){
        printf("1");
        a22=a22+10*(s2[0]-'0');

        a22=a22+(s2[1]-'0');


        b22=b22+10*(c2[0]-'0');
        b22=b22+(c2[1]-'0');
        if (b22 == a22){
            printf("1");
            if (s2[2]=='C' && c2[2]=='D' || s2[2]=='C'&& c2[2]=='D'){
                printf("00");
            }
            else{
            	printf("1");
               if (s2[2]=='C' && c2[2]=='A' || s2[2]=='A' && c2[2]=='C'){
               	    printf("0");
			   }
			   else{
			   	    printf("1");
			   }
            }

        }
        else{
            printf("000");
        }
    }
    else{
        printf("0000");
    }
    return 0;


}
