#include <bits/stdc++.h>
using namespace std;
typedef struct date{
    int num;
    char y;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    vector<date>dp(n),pd(n);
    for(int i=0;i<n;i++){
        cin>>dp[i].num>>dp[i].y;
        pd[n-i-1].num=dp[i].num;
        pd[n-i-1].y=dp[i].y;
    }
    int i=0,j=0;
    long long cnt=0;
    while(i<n && j<n){
       date num1=dp[i],num2=pd[j];
       if(num1.y==num2.y){
            if(num1.num==num2.num){
                i++;
                j++;
            }else if(num1.num>num2.num){
                dp[i].num-=num2.num;
                j++;
            }else{
                pd[j].num-=num1.num;
                i++;
            }
       }else{
           if(num1.num==num2.num){
                cnt+=num1.num;
                i++;
                j++;
           }else if(num1.num>num2.num){
                dp[i].num-=num2.num;
                cnt+=num2.num;
                j++;
           }else{
                pd[j].num-=num1.num;
                cnt+=num1.num;
                i++;
            }
       }
    }cout<<cnt/2<<endl;
    return 0;
}
