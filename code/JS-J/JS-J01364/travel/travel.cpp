#include <bits/stdc++.h>
using namespace std ;
int main(){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    int a,b  ;
    string c1,c2 ;
    cin >> a >> c1 ;
    cin >> b >> c2 ;
    string s1 = c1.substr(0,2) ;
    string s2 = c2.substr(0,2)  ;
    if(a == b){
        if(s1 == s2) {
            if((c1[2] <='C' && c2[2]<='C')||(c1[2]>='D' && c2[2]>='D')){
                if(abs(c1[2]-c2[2])==1 || (c1[2] >='D' && abs(c1[2]-c2[2]) == 2)){
                    printf("1111") ;
                }else{
                    printf("1110") ;
                }
            }else{
                printf("1100") ;
            }
        }else{
            printf("1000") ;
        }
    }else{
        printf("0000") ;
    }
    return 0 ;
}
