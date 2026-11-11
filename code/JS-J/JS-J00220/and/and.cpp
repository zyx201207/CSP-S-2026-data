#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],dp[N],sum=-1e18;
long long n,m;
bool ok[N];
int solve(){
    long long maxn=-1e18;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            maxn=max(maxn,a[i]&a[j]);
        }
    }
    return maxn;
}
void dfs(long long x,long long cnt){
    if(x==0){
        sum=max(sum,cnt);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!ok[i]){
            ok[i]=true;
            dfs(x-1,cnt&a[i]);
            ok[i]=false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==2){

        cout<<solve();
    }
    else if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
    }
    else if(m==n){
        long long ans=a[1];
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
    }
    else if(m==n-1){
        long long ans=a[1],maxn=-1e9;
        for(int i=2;i<=n;i++){
            ans&=a[i];
        }
        for(int i=1;i<=n;i++){
            maxn=max(maxn,ans|a[i]);
        }
        cout<<maxn;
    }
    else{
        for(int i=1;i<=n;i++){
            ok[i]=true;
            dfs(m-1,a[i]);
            ok[i]=false;
        }
        cout<<sum;
    }
    return 0;
}
