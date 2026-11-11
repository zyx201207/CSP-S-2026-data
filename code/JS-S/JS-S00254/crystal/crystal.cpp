#include<bits/stdc++.h>
using namespace std;
long long n,m,a[700005],ans=-1e9,m1,cnt;
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","r",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
for(int i=2;i<=n;i++){
    m1=m,cnt=0;
    for(int j=i-1;j>0;j--){
        if(m1-abs(a[i]-a[j])>=0)cnt++,m1-=abs(a[i]-a[j]);
        else break;
    }
    ans=max(ans,cnt+1);
}
cout<<ans;
return 0;
}
