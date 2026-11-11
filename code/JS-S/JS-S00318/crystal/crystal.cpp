#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,l,ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    long long sum=0,l=1;
    for(int i=1;i<=n;i++){
        while((i-l)*a[i]-sum>m){
            sum-=a[l];
            l++;
        }
        ans=max(ans,i-l+1);
        sum+=a[i];
    }
    cout<<ans;
    return 0;
}
