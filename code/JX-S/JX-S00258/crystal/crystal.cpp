#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500010],sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    sum=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int l=1;
    for(int i=1;i<=n;i++){
        sum-=(i-l)*(a[i]-a[i-1]);
        while(sum<0){
            sum+=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
