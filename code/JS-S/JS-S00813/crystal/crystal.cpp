#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],n,d[N];
ll m,now,sum[N];
ll ans;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);

cin>>n>>m;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=2;i<=n;i++){
    d[i]=a[i]-a[i-1];
}
for(int i=2;i<=n;i++){
    sum[i]=d[i]*(i-1)+sum[i-1];
}
for(int i=2;i<=n;i++){
    int j=0;
    while(i>j&&sum[i]-sum[j]>m)j++;
    if(i-j>ans)ans=(ll)i-j;
}
cout<<ans;
return 0;
}
