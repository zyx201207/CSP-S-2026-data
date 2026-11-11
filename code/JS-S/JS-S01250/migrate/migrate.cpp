#include<bits/stdc++.h>
using namespace std;
const long long N=500005;
long long n,m;
long long a[N],maxn=-1,sum[N];
int main(){
   // freopen("crystal.in","r",stdin);
   // freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    sum[0]=0;
    for(long long i=1;i<=n;++i){
        sum[i]=sum[i-1]+a[i];
    }
    for(long long i=1;i<=n;++i){
        long long j=i,cnt=0;
        while(j>=1){
            cnt=a[i]*(i-j+1)-sum[i]+sum[j-1];
            if(cnt>m) break;
            --j;
        }
        maxn=max(maxn,i-j);
    }
    cout<<maxn<<endl;
    return 0;
}
