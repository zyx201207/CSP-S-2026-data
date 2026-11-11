#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    getline(cin,s);
    if(s[0] == s[7] && s[1] == s[8]){
        printf("%d",1);
        if(s[3] == s[10] && s[4] == s[11]){
            printf("%d",1);
            if(('A' <= s[5] && s[5] <= 'C') && ('A'<= s[12] && s[12] <= 'C')){
                printf("%d",1);

                if((s[5] == 'A' && s[12] == 'B')||(s[5] == 'B' && s[12] == 'A'))
                    printf("%d",1);
                else if((s[5] == 'C' && s[12] == 'B')||(s[5] == 'B' && s[12] == 'C'))
                    printf("%d",1);
                else printf("%d",0);
            }
            else if((s[5] == 'E' && s[12] == 'F')||(s[5] == 'F' && s[12] == 'E')){
                printf("11");
                return 0;
            }else{
                printf("00");
                return 0;
            }
        }
        else printf("000");
    }
    else
        printf("0000");



    return 0;

}
