#include<bits/stdc++.h>
using namespace std;
bool testify(string a){
    for(long long i=0;i<=a.size()/2;i++){
        if(a[i]!=a[a.size()-i-1])
            return false;
    }
    return true;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T;
    string s="";
    scanf("%d",&T);
    while(T--){
        int k;
        char c;
        scanf("%d %c",&k,&c);
        while(k--){
            s+=c;
        }
    }
    long long len=s.size()-1;
    if(testify(s)){
        printf("0\n");
        return 0;
    }
    long long dp[len+5][len+5];
    for(long long i=1;i<=s.size();i++){
        for(long long j=1;j<=s.size();j++){
            if(s[i]==s[j])
                dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
        }
    }
    printf("%lld\n",dp[len][len]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
