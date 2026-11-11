#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005];
long long s[500005];
bool check(int id){
	for(int i=id;i<=n;i++){
		int from=i-id+1;
		long long need=s[i]-s[from-1]-(a[id]-a[from-1])*(from-1);
		if(need<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	s[1]=0;
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(i-1)*(a[i]-a[i-1]);
	} 
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
