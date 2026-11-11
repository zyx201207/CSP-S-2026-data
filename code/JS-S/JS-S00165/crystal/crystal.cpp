#include <bits/stdc++.h>
using namespace std;
int n,j,ans=1;
long long m,sum;
long long a[500010];
int main(){
    !freopen("crystal.in","r",stdin);
    !freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++){
        sum+=(a[i]-a[i-1])*(i-j);
        while(sum>m){
            sum-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
    return 0;
}