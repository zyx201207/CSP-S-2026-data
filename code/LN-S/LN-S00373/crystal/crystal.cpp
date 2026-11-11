#include<bits/stdc++.h>
using namespace std;
long long b[50001],a[50001];
bool cmp(long long a,long long b){
    return a>b;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }long long ans=0;
    sort(a+1,a+n+1,cmp);
    long long ma=INT_MIN;
    for(int i=1;i<=n;i++){
            long long sum=m;
            ans=0;
        for(int j=i;j<=n;j++){
            if(sum-(a[i]-a[j])>=0){
                ans++;
                sum-=a[i]-a[j];
            }else{
                break ;
            }

        }
        ma=max(ma,ans);

    }
    printf("%lld",ma);
    return 0;
}
