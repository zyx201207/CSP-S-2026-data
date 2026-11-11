#include<bits/stdc++.h>
using namespace std;
long long a[500010],s[500010];

void solve(){
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n+1;
		while(l<r){
			int mid=(l+r)/2;
			if(a[mid]*(mid-i+1)<=m+s[mid]-s[i-1]){
				l=mid+1;
			}
			else{
				r=mid;
			}
		}
		ans=max(ans,l-i);
		//cerr<<i<<" "<<l-1<<"\n";
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	return 0;
}
