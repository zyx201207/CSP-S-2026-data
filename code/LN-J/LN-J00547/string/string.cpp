#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string .in","r",stdin);
    freopen("string .out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin>>m;
    deque<long long> dp;
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        for(int j=0;j<a;j++){
        dp.push_front(b);
        }
    }
    long long cnt=dp.size();
    long long r=0,l=dp.size();
    while(r<l){
        if(reverse(dp[r+1],dp[l])==dp){
            dp.pop_front();
        }
        if(reverse(dp[r],dp[l-1])==dp){
            dp.pop_back();
            l--;
        }
        if(reverse(dp[r+1],dp[l])!=dp&&reverse(dp[r],dp[l-1])!=dp){
            dp.pop_front();
            dp.pop_back();
            l--;
        }
        if(reverse(dp[r],dp[l])==dp){
            cout<<cnt-dp.size();
        }
    }
return 0;
}
