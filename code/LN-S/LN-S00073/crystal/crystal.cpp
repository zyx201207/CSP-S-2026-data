#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600005];
struct Node{
  long long num;
  long long zuobiao;

}dp[600005];
bool cmp(Node a,Node b){
return a.num<b.num;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i].num+=a[i]-a[j];
            dp[i].zuobiao=i;
        }
    }
    sort(dp+1,dp+n+1,cmp);
    for(int i=2;i<=n;i++){
        if(m==dp[i].num){
            cout<<i;
            return 0;
        }
        if(m>dp[i-1].num&&m<dp[i].num){
            cout<<i-1;
            return 0;
        }
    }

return 0;
}
