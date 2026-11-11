#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],s[N];
int sum[N];
int n,m,ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=a[i]-a[i-1];
        sum[i]=sum[i-1]+s[i];
    }
    int now=0;
    for(int l=1,r=1;l<=n&&r<=n;l++){
        while(r+1<=n&&now+s[r+1]*(r+1-l)<=m){
            now+=s[r+1]*(r+1-l);
            r++;
        }
        ans=max(ans,r-l+1);
        now-=a[r]-a[l];
    }
    cout<<ans;
    return 0;
}
