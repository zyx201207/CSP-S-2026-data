#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=0,mx=0;
long long a[200005];
long long yu(long long x,long long y){
    long long x1=0;
    long long y1=0;
    long long q=1;
    long long cnt=0;
    long long ans=0;
    while(x>0){
        x1+=x%2*q;
        x/=2;
        q*=10;
    }
    q=1;
    while(y>0){
        y1+=y%2*q;
        y/=2;
        q*=10;
    }
    q=1;
    while(x1>0 && y1>0){
        if(x1%10==y1%10 && x1%10==1){
            cnt+=q;
        }
        q*=10;
        x1/=10;
        y1/=10;
    }
    q=1;
    while(cnt>0){
        ans+=cnt%10*q;
        q*=2;
        cnt/=10;
    }
    return ans;

}
vector<long long> dp;
void f(int i){
    if(dp.size()==m){
        long long d=dp[0];
        for(int k=1;k<dp.size();k++){
            d=yu(d,dp[k]);
        }
        mx=max(mx,d);
        return;
    }
    if(i>n) return;
    for(int k=i;k<=n;k++){
        dp.push_back(a[k]);
        f(k+1);
        dp.pop_back();
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(m==1){
        cout<<ma;
    }
    else if(m==n){
        long long d=a[1];
        for(int i=2;i<=n;i++){
            d=yu(d,a[i]);
        }
        cout<<d;
    }
    else{
        f(1);
        cout<<mx<<endl;
    }
    return 0;
}
