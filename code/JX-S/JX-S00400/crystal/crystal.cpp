#include <bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500001],d[500000];
bool check(int x){
    long long sum;
    bool o;
    for(int i=n-2;i>=x-2;i--){
        o=true;sum=0;
        for(int j=i,tmp=x-1;tmp>0;j--,tmp--){
            sum+=long(d[j]*tmp);
            if(sum>m){o=false;break;}
        }
        if(o) return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=0;i<n;i++) scanf("%lld", &a[i]);
    sort(a,a+n);
    for(int i=0;i<n-1;i++) d[i]=a[i+1]-a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    printf("%d",ans);
    return 0;
}
