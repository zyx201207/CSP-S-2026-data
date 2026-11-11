#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],d[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    long long sum=0;
    int l=1;
    for(int i=1;i<=n;i++){
        sum+=(a[i]-a[i-1])*(i-l);
        while(sum>m&&l<=i){
            sum-=a[i]-a[l];
            l++;
        }
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}
