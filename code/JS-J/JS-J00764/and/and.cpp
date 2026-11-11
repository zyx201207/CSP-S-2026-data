#include<bits/stdc++.h>
using namespace std;
int a[10000005];
bool b[10000005];
int dp[10000005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int MAX=1024;
    for(int i=10;i<=30;i++){
        MAX*=2;
    }
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=MAX-1;
    for(int i=1;i<=m;i++){
            int maxl=-1;
            int st;
       for(int j=1;j<=n;j++){
           int x=a[j]&dp[i-1];
           if(x>maxl){
            st=j;
            maxl=x;
           }
      }
      a[st]=0;
      dp[i]=maxl;
    }
    cout<<dp[m];
    return 0;
}
