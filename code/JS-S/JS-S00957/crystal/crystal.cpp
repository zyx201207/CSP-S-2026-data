#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,ans=1;
long long m,a[N],s[N],d[N];
bool cmp(long long a,long long b){
    return a<b;
}
int erfen(int i,int r){
    int l=1;
    while(l<r){
        int mid=(l+r)>>1;
        if(s[i]-s[mid]-(d[i]-d[mid])*(mid-1)>m) l=mid+1;
          else r=mid;
    }
    ans=i-l+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(int i=2;i<=n;i++){
        d[i]=d[i-1]+a[i]-a[i-1];
        s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
    }

    for(int i=1;i<=n;i++) erfen(i,i-ans+1);
    printf("%d",ans);
    return 0;
}
