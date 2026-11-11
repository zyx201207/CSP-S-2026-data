#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
bool d=true;
long long a[500050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<n;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i]){
            d=false;
        }
    }
    if(d){
        long long x=a[2]-a[1],num=a[2]-a[1];
        for(long long i=2;i<=n;i++){
            if(num>m){
                break;
            }
            ans++;
            num+=x*((i+1)/2);
        }
        ans++;
    }else{
        for(long long i=1;i<=n;i++){
            long long x=m,y=0;
            for(long long j=i;j>=1;j--){
                if(x<a[i]-a[j]){
                    break;
                }else{
                    x-=a[i]-a[j];
                    y++;
                }
            }
            ans=max(y,ans);
        }
    }
    cout<<ans;
    return 0;
}
