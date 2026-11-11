#include<bits/stdc++.h>
using namespace std;

int const N=5e5;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long  m;
    cin>>n>>m;
    //cout<<n<<' '<<m<<endl;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    sort(a+1,a+1+n);
    int dp[N];
    unsigned long long cost=0,l=1;
    for(int i=1;i<=n;i++){
        cost+=(a[i]-a[max(1,i-1)])*(i-l);
        //cout<<cost<<' '<<l<<' ';
        while(cost>m){
            cost-=a[i]-a[l];
            l++;
        }
        dp[i]=i-l+1;
        //cout<<cost<<' '<<l<<endl;
    }
    for(int i=1;i<=n;i++){
            //cout<<dp[i]<<endl;
            ans=max(dp[i],ans);
    }
    cout<<ans;
}
