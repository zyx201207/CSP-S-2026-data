#include<bits/stdc++.h>
using namespace std;
long long a[500100],s[500100];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,i,ans=0;
	long long m;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(i=2;i<=n;i++) s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	for(i=1;i<=n;i++){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(s[i]-(mid-1)*(a[i]-a[mid])-s[mid]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
