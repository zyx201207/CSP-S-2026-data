#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],ans;
bool f(int a,int b){
    int dp[b-a+1];
    dp[0]=0;
    for(int i=1;i<b-a+1;i++){
        if(x[i+a]-x[i+a-1]>d){
            return false;
        }
        dp[i]=1e9;
        for(int j=i-1;j>=0;j--){
            if(x[i+a]-x[j+a]>d){
                break;
            }
            dp[i]=min(dp[i],dp[j]+1);
        }
    }
    if(dp[b-a-1]==dp[b-a-2]&&dp[b-a-1]!=dp[b-a]&&dp[b-a-2]!=dp[b-a-3]){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>d;
        ans=0;
        for(int j=0;j<n;j++){
            cin>>x[j];
        }
        for(int j=0;j<n;j++){
            for(int k=j+3;k<n;k++){
                if(f(j,k)){
                    ans++;
                }
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
