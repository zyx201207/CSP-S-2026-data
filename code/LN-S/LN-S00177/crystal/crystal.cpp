#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    scanf("%lld%lld",&n,&m);
    long long a[n];
    for(long long i=0;i<n;i++){scanf("%lld",&a[i]);}
    sort(a,a+n,greater<long long>());
    long long ans=-1;
    for(long long i=0;i<n;i++){
        long long b[n-i],cnt=m,sum=1;
        if(n-i<=ans)break;
        if(a[i]==a[i-1])continue;
        for(long long j=i+1;j<n;j++){
            b[j]=a[i]-a[j];
            cnt-=b[j];
            if(cnt>=0)sum++;
            else break;
        }
        ans=max(ans,sum);
    }
    printf("%lld",ans);
    return 0;
}
