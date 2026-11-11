#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],m;
int n;
bool check(int x){
    if(x==1)
        return true;
    for(int i=1;i<=n-x+1;i++){
        int j=i+x-1;
        if(a[j]*(x-1)-(s[j-1]-s[i-1])<=m)
            return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l+1<r){
        int mid=(l+r)/2;
        if(check(mid))
            l=mid;
        else
            r=mid;
    }
    printf("%d",l);
    return 0;
}
