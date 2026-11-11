#include <bits/stdc++.h>
using namespace std;

const int Max = 2e6+5;

int c,t;
int n;
long long d,x[Max];
int dp[5005][5005];
int bd[5005][5005][2];
long long sum[5005][5005];
int temp[Max];

void input(){
    scanf("%d%lld",&n,&d);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&x[i]);
    }
}
long long get_ans1(int ll,int rr){
    long long ans = 0;
    for(int i = ll; i <= rr; i++){
        temp[i-ll+1] = x[i];
    }
    int tempn = rr-ll+1;
    for(int i = 1; i <= tempn; i++){
        int lst = lower_bound(temp+1,temp+tempn+1,temp[i]-d)-temp;
        //printf("%d ",lst);
        for(int j = 1; j < i; j++){
            if(j >= lst) dp[j][i] = 1;
            else dp[j][i] = dp[j][lst]+1;
            int ll = max(bd[j][dp[j][i]-1][0],lst),rr = min(bd[j][dp[j][i]-1][1],i-1);
            int cnt = 1;
            if(dp[i][j] != 1 && rr >= ll) cnt = sum[j][rr]-sum[j][ll-1];
            if(cnt == 2) ans++;
            sum[j][i] = sum[j][i-1]+cnt;
            if(dp[j][i] != dp[j][i-1]) bd[j][dp[j][i]][0] = i;
            bd[j][dp[j][i]][1] = i;
        }
    }
    return ans;
}

void solve1(){
    while(t--){
        long long ans = 0;
        input();
        int lst = 0;
        for(int i = 1; i <= n; i++){
            if(i == n || x[i+1]-x[i] > d){
                ans += get_ans1(lst+1,i);
                lst = i;
                //clean();
            }
        }
        printf("%lld\n",ans);
    }
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c <= 10){
        solve1();
        return 0;
    }
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
10 272727272727272724
-999999999999999976 -727272727272727252 -454545454545454528 -181818181818181804 -90909090909090896 12 181818181818181828 454545454545454552 727272727272727276 1000000000000000000
*/
