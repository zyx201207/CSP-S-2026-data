#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,now,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=r=n;
	while(now+a[n]-a[l-1]<=m&&l>1){
		l--;
		now+=a[n]-a[l];
	}
	ans=r-l+1;
	while(l<=r){
		now-=(a[r]-a[r-1])*(r-l);
		r--;
		while(now+a[r]-a[l-1]<=m&&l>1){
			l--;
			now+=a[r]-a[l];
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}