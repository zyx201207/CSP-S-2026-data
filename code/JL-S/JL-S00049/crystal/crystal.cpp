#include<bits/stdc++.h>
using namespace std;//239
#define int long long
int a[500005];
int num[500005];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int ans=0;
    int cnt=0;
    int l=1;
    for(int i=1;i<=n;i++){
        int pos=n;
        for(int j=i+1;j<=n;j++){
            if(a[j]!=a[i]){
                pos=j-1;
                break;
            }
        }
        cnt=(cnt+(i-1-l+1)*(a[i]-a[i-1]));
        while(l<i&&cnt>m){
            cnt-=(a[i]-a[l]);
            l++;
        }
        i=pos;
        ans=max(i-l+1,ans);
    }
    cout<<ans;
    return 0;
}