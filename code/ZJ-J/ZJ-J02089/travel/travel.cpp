#include <bits/stdc++.h>
using namespace std;
// no  01 16
// T1 8.30 9.06 all-AC
#define ll long long
string s1,s2;
ll c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%lld",&c1);
    cin >> s1;
    scanf("%lld",&c2);
    cin >> s2;
    //02 01A 03 01A

    if(c1 == c2){
        printf("1");
    }else{
        printf("0000");
        return 0;
    }
    int t1,t2;
    t1 = s1[0] - '0';
    t2 = s2[0] - '0';
    if(t1 != t2){
        printf("000");
        return 0;
    }
    
    t1 = s1[1] - '0';
    t2 = s2[1] - '0';
    if(t1 != t2){
        printf("000");
        return 0;
    }
// 02 01C 02 01D
    printf("1");
    if(s1[2] - s2[2] == 1 || s2[2] - s1[2] == 1){
        if(s1[2] == 'C' && s2[2] == 'D'){// C and D
            printf("00");
            return 0;
        }else if(s2[2] == 'C' && s1[2] == 'D'){
            printf("00");
            return 0;
        }
        printf("11");
    }else if(s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
        if(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
            printf("10");
        }
    }else{
        printf("00");
    }
    return 0;
}