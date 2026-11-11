#include<bits/stdc++.h>
using namespace std;
char c1[10], s1[10], c2[10], s2[10];
int sum[1010];
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    scanf("%s%s%s%s", c1 + 1, s1 + 1, c2 + 1, s2 + 1);
    sum['A' - '0'] = sum['B' - '0'] = sum['C' - '0'] = 0;
    sum['D' - '0'] = sum['F' - '0'] = 1;
    bool flag = true;
    for(int i = 1; i <= 2; i ++){
        if(c1[i] != c2[i]){
            flag = false;
            break;
        }
    }
    if(!flag){
        printf("0000\n");
    }
    else{
        for(int i = 1; i <= 2; i ++){
            if(s1[i] != s2[i]){
                flag = false;
                break;
            }
        }
        if(!flag){
            printf("1000\n");
        }
        else{
            if(sum[s1[3] - '0'] != sum[s2[3] - '0']){
                printf("1100\n");
            }
            else{
                if(abs((s1[3] - '0') - (s2[3] - '0')) == 1 || s1[3] == 'D' && s2[3] == 'F' || s1[3] == 'F' && s2[3] == 'D'){
                    printf("1111\n");
                }
                else{
                    printf("1110\n");
                }
            }
        }
    }
    return 0;
}