#include <bits/stdc++.h>
using namespace std;

int n,t[200010];
char s[200010],c[200010],m[300010];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for (int i = 1;i <= n;i++){
        scanf("%d%s",&t[i],s + 1);
        c[i] = s[1];
    }
    if (n == 1){
        printf("0");
    }
    else{
        if (n == 2){
            if (c[1] != c[2]){
                printf("%d",min(t[1],t[2]));
            }
            else{
                printf("0");
            }
        }
        else{
            int lm = 0;
            for (int i = 1;i <= n;i++){
                for (int j = 1;j <= t[i];j++){
                    lm++;
                    m[lm] = c[i];
                }
            }
            int sum1 = 0,sum2 = 0;
            for (int i = 1;i <= lm / 2;i++){
                if (m[i] != m[lm - i + 1]){
                    sum1++;
                }
            }
            for (int i = lm;i > lm / 2;i--){
                if (m[i] != m[lm - i + 1]){
                    sum2++;
                }
            }
            printf("%d",min(sum1,sum2));
        }
    }
    return 0;
}
