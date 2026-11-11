#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N],m,sum[N];
int n;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,ans=0;
    for(int r=1;r<=n;r++){
        while(l<r&&a[r]*((ll)(r-l+1))-(sum[r]-sum[l-1])>m){
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans<<'\n';
}