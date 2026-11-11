#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;long long m,a[N];
int ans;long long sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }sort(a+1,a+n+1);
    ans=1,sum=a[1];
    for(int l=1,r=2;r<=n;r++){
        sum+=a[r];int len=r-l+1;
        long long temp=a[r]*len-sum;
        while(temp>m){
            sum-=a[l];temp-=(a[r]-a[l]);l++;
        }
        len=r-l+1;
        if(ans<len) ans=len;
    }
    printf("%d",ans);
    return 0;
}