#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
long long n;
long long ans=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n;
for(long long i=1;i<=n;i++){
    cin>>a[i]>>c[i];
}
long long l=1,r=n;
while(l<r){
    long long mii=min(a[l],a[r]);
    a[l]-=mii;
    a[r]-=mii;
    if(c[l]!=c[r]) ans+=mii;
    if(a[l]==0) l++;
    if(a[r]==0) r--;
}
cout<<ans;
return 0;
}
