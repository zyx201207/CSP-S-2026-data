#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n>5000){
        int x=a[2]-a[1];
        for(int i=2;i<=n;i++){
            int tmp=i*(i-1)/2;
            if(tmp*x<=m) ans=i;
        }
    }
    else{
        for(int i=2;i<=n;i++){
            int sum=0,cnt=0;
            for(int j=i;j>=1;j--){
                sum+=(a[i]-a[j]);
                cnt++;
                if(sum>m) break;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
    return 0;
}
