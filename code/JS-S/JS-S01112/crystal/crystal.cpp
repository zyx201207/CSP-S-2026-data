#include <bits/stdc++.h>
using namespace std;
int n,j,ans;
long long m,a[555555],sum,lst=-1e14;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    j=n;
    for(int i=n;i>=1;i--){
        if(lst!=-1e14)
            sum=sum-(lst-a[i])*((i+1)-j);
        while(j>=1){
            if(sum+(a[i]-a[j])<=m){
                j--;
                sum+=(a[i]-a[j]);
            }
            else
                break;
        }
        ans=max(ans,i-j+1);
        lst=a[i];
    }
    cout<<ans<<endl;
}
