#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N];
long long n,m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    long long i=1,j=1,ans=-1e18,sum=0;
    while(i<n&&j<n){
        sum=sum+(i-j+1)*(a[i+1]-a[i]);
        i++;
        while(sum>m){
            sum=sum-(a[i]-a[j]);
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans;
}
