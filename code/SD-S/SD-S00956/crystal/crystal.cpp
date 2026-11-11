#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],r,ans=0,x=0;
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n;i++){
  	cin>>a[i];
	}sort(a+1,a+n+1);
	r=1;
	for(long long l=1;l<=n&&r<=n;l++){
		while(r<=n&&x<=m){
			r++;
			x+=(r-l)*(a[r]-a[r-1]);
		}x-=(r-l)*(a[r]-a[r-1]);
		r--;
		ans=max(ans,r-l+1);
		x-=a[r]-a[l];
	}cout<<ans;
  return 0;
}
