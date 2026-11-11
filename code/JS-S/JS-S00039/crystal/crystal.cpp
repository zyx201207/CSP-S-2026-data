#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N],cnt[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cnt[1]=0;
    for(long long i=2;i<=n;i++){
        cnt[i]=cnt[i-1]+((i-1)*(a[i]-a[i-1]));
    }
    long long ans=0;
    for(long long i=n;i>=2;i--){
        for(long long j=1;j<=n;j++){
            long long tmp=(cnt[i]-cnt[j])-(a[i]-a[j])*(j-1);
            if(tmp<=m)ans=max(ans,i-j+1);
        }
    }
    cout<<ans;
    return 0;
}
