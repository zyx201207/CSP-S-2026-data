#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main()
{
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
cin>>n>>m;
for(long long i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
long long l=1,r=1;
for(int i=1;i<=n;i++){
    b[i]=b[i-1]+a[i];
}
for(;r<=n;r++){
if(a[r]*(r-l+1)-(b[r]-b[l-1])>m){
    while(l<=r){
        if(r-l+1<ans){
            break;
        }
        if(a[r]*(r-l+1)-(b[r]-b[l-1])<=m){
            ans=max(ans,r-l+1);
            break;
        }
        l++;
    }
}else{
ans=max(ans,r-l+1);
}
}
cout<<ans<<" ";
    return 0;
}
