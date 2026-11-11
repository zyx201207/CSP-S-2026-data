#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],ans,cnt,aa;
long long xiwang(long long j){
    long long ans1=j,cnt1=0,b[1000000];
    for(int i=1;i<=n;i++){
        b[i]=ans1-a[i];
    }
    long long p=m;
    for(int i=1;i<=n;i++){
        if(p-b[i]>=0 && b[i]>=0){
            cnt1++;
            p-=b[i];
        }
    }
    //cout<<cnt1<<endl;
    return cnt1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    sort(a+1,a+1+n);
    ans/=n;
    int d=1;
    if(n>1000){
        d=5;
    }
    for(int j=ans;j>=ans-500000;j-=d){
        if(xiwang(j)<cnt){
            break;
        }
        cnt=max(cnt,xiwang(j));
    }
    for(int j=ans;j<=ans+500000;j+=d){
        if(xiwang(j)<cnt){
            break;
        }
        cnt=max(cnt,xiwang(j));
    }
    cout<<cnt;
    return 0;
}
