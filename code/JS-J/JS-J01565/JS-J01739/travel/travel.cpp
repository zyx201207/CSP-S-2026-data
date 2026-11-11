#include<bits/stdc++.h>
using namespace std;
int c1,c2,n1,n2,m1,m2;
string s1,s2;
char t;
int main(){
    freopen("travel.in","r",stdin);
    cin>>c1>>s1>>c2>>s2;
    freopen("travel.out","w",stdout);
    if(c1!=c2){
        printf("%s","0000");
        return 0;
    }
    n1=(s1[0]-'0')*10+(s1[1]-'0');
    n2=(s2[0]-'0')*10+(s2[1]-'0');
    m1=s1[2]-'A'+1;
    m2=s2[2]-'A'+1;
    if(n1!=n2){
        printf("%s","1000");
        return 0;
    }
    if((m1-3<=0)!=(m2-3<=0)){
        printf("%s","1100");
        return 0;
    }
    if(abs(m1-m2)!=1){
        printf("%s","1110");
        return 0;
    }
    printf("%s","1111");
    return 0;
}
