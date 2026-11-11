#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005];
ll c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
   ll m;int n;
   cin>>n>>m;
   for(int i=1;i<=n;i++)cin>>a[i];
   sort(a+1,a+1+n);
   for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
   
//  for(int i=2;i<=n;i++)cout<<c[i]<<" ";
   ll ans=-1;
   for(int i=2;i<=n;i++){
	   ll cnt=1;ll sum=0;
	   for(int j=i;j<=n&&sum+cnt*c[j]<=m;j++){
		   sum+=cnt*c[j];
		   cnt++;
	   }
	   ans=max(ans,cnt);
   }
   cout<<ans;
}
	   
		   

