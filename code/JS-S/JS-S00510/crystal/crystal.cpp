#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=LONG_LONG_MIN;
int a[500010],b[500010];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    int l=1,cnt=0,sum=0;
    for(int r=2;r<=n;r++){
        cnt+=b[r]*(r-l);
        sum+=b[r];
        while(cnt>m){
            cnt-=sum;
            sum-=b[l];
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
