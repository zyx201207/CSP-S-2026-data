#include<bits/stdc++.h>
using namespace std;
struct NUM{
    long long one;
    long long sum;
}a[200010];
long long check(long long x,long long y){
    long long mi=0;
    long long maxx=0;
    while(min(x,y)){
        if(x%2==1&&y%2==1){
            maxx+=(1<<mi);
        }
        mi++;
        x/=2;
        y/=2;
    }
    //cout<<x<<" "<<y<<" "<<maxx<<endl;
    return maxx;
}
long long check1(long long x){
    long long maxx=0;
    while(x){
        if(x%2==1) maxx++;
        x/=2;
    }
    return maxx;
}
bool cmp(NUM x,NUM y){
    if(x.one==y.one) return x.sum<y.sum;
    return x.one>y.one;
}
unordered_map<long long,long long> ma;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long stupid=0;
    for(long long i=1;i<=n;i++){
        cin>>a[i].sum;
        ma[a[i].sum]++;
        if(ma[a[i].sum]==m) stupid=max(stupid,a[i].sum);
        a[i].one=check1(a[i].sum);
    }
    sort(a+1,a+n+1,cmp);
    long long maxx=a[1].sum;
    for(long long i=2;i<=m;i++){
        maxx=check(maxx,a[i].sum);
    }
    cout<<max(maxx,stupid)<<endl;
    return 0;
}
//dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
