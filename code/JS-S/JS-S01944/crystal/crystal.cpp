#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum,sm,ma,now=1ll;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(long long i=2ll;i<=n;i++){
        sum+=a[i]-a[i-1];
        sm+=(a[i]-a[i-1])*(i-now);
        while(sm>m){
            sm-=sum;
            sum-=a[now+1]-a[now];
            now++;
        }
        ma=max(ma,i-now+1ll);
    }
    cout<<ma;
    return 0;
}
