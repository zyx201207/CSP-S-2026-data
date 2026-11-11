#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans=1;
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i+1]||i==n){
            long long cnt=1,x=m;
            for(int j=i-1;j>=1;j--){
                if(a[i]-a[j]<=x){
                    cnt++;
                    x-=(a[i]-a[j]);
                }else break;
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
    return 0;
}
