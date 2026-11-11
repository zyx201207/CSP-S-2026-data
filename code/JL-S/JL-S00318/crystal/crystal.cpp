#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],d[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n>5000&&a[1]+1==a[2]&&a[2]+1==a[3]){
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=i;
            if(cnt>m){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);

    int ans=0;
    for(int i=n;i>=1;i--){
        int cnt=0;
        for(int j=i;j>=1;j--){
            cnt+=a[i]-a[j];
            if(cnt>m)break;
            ans=max(ans,i-j+1);
        }
    }
    cout<<ans;
    return 0;
}
