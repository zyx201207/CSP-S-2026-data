#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-1;
int a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        int sum=0;
        for(int j=n-1;j>=1;j--){
            sum+=a[i]-a[j];
        }
        int j=1,cnt=i;
        while(sum>m){
            sum-=a[i]-a[j];
            j++;
            cnt--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
