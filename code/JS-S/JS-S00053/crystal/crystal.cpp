#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
long long sum[N];
int n,m;
long long f(int l,int r){
    return sum[r]-sum[l]-(a[r]-a[l])*l;
}
int main(){
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
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(a[i]-a[i-1])*i;
    }
    int l=1;
    int ans=0;
    for(int r=1;r<=n;r++){
        while(l<r&&f(l,r)>m){
            l++;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
