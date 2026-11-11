#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum,ans,maxn=1;
int main(){
    freopen("ctystal.in","r",stdin);
    freopen("ctystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==0){
        cout<<0;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++){
        sum=m;
        ans=1;
        for(int j=i-1;j>=1;j--){
            if(sum>=0 && sum>=a[i]-a[j]){
                sum-=a[i]-a[j];
                ans++;
            }else{
                break;
            }
        }
        maxn=max(ans,maxn);
    }
    cout<<maxn;
    return 0;
}
