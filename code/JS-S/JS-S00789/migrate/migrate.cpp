#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 +10
int n,d,a[N];
int main(){
    int c,f;
    scanf("%d%d",&c,&t);
    while(t--){
        scanf(("%d%d",&n,&d);
        for (int i = 1, i<= n, i++){
            scanf(("%d",&a[i])
        }
        for(int i = 1;i <= n; i++){

            for(int j = i + 1; j++){
                    memset(dp,0,sizeof(dp))
                for(int k = j;k<= n; k++){
                    if(a[j] - a[k] <= d){
                        dp[j] +=dp[k]
                        if (dp[j]<=2){
                            break
                        }
                  }
            }
        }

    }
    freopen("migrate.in","r",stdin);
    freopen("migrate.out""w",stdout);
    return 0;
}
