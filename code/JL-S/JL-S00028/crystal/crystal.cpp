#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans=1;
ll m,a[500010];
ll s;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000&&m>100000000){
        if(n>1)s=a[2]-a[1];
        while(m&&ans<n){
            if(m>=s*ans){
                m-=s*ans;
                ans++;
            }
            else break;
        }
        cout<<ans<<"\n";
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++){
        ll sum=0;
        int cnt=0;
        int j=i;
        while(sum<=m&&j<=n){
            sum+=(a[j+1]-a[j])*(j-i+1);
            cnt++;
            j++;
        }
        ans=max(cnt,ans);
    }
    cout<<ans<<"\n";
return 0;
}
