#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
// 5 5 1 2 4 8 9
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1,0);
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	long long l=0,r=0,cnt=0,ans=0;
	while(l<=n&&r<=n){
		l++;
		while(cnt<=m&&r<=n){
			ans=max(ans,r-l+1);
			r++;
			cnt+=(a[r]-a[r-1])*(r-l);
		}
		cnt-=a[r]-a[l];
	}
	cout<<ans;
}