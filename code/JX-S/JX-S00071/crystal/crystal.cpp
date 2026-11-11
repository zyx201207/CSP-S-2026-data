#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
const int maxn=5e5+5;
ll m,a[maxn],s[maxn];
bool chk(int len){
    for(int i=len;i<=n;i++){
        if((len*a[i]-s[i]+s[i-len])<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(chk(mid))l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}
