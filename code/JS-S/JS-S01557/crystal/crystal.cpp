#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],ans,f[500010],t[2000],l,r;
bool check(ll p){
for(int i=1;i+p-1<=n;i++)
    if((p-1)*a[i+p-1]-f[i+p-2]+f[i-1] <= m) {
    l=i,r=i+p-1;
    return true;
}
return false;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
cin >> n >> m;
for(int i=1;i<=n;i++) cin >> a[i];
sort(a+1,a+n+1);
for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
ll L=1,R=n,mid,ans=1;
while(L<=R){
    mid=L+R>>1;
    if(check(mid)){
        ans=mid;
        L=mid+1;
    }else R=mid-1;
}
cout << ans;
return 0;
}
