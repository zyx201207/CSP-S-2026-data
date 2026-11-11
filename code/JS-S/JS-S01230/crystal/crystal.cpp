#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],sum[500005];
int flag=true;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>=2) sum[i]=a[i]-a[i-1];
        if(sum[i]!=sum[i-1]&&i>=3) flag=false;
    }
    sort(a+1,a+n+1);
    int ans=1;
    if(flag==false){
        for(int i=1;i<=n;i++){
        int c=m,cnt=1;
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]>c){
               ans=max(ans,cnt);
               break;
            }  else {
                c-=(a[i]-a[j]);
                cnt++;
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    } else{
        double x=sum[2];
        if(ceil(sqrt(double(m*2/x)))>n) cout<<n;
        else cout<<ceil(sqrt(double(m*2/x)));
    }

    return 0;
}
