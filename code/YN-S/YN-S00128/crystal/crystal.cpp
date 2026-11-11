#include<stdio.h>
#include<iostream>
#include<algorithm>
const int N=500010;
using namespace std;
int n,mx;long long m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            if(s[i]-s[mid-1]+m<(i-mid+1)*a[i])l=mid+1;
            else r=mid;
        }mx=max(mx,i-l+1);
    }cout<<mx;
    return 0;
}
