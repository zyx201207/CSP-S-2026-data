#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[501010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int r=1;
	long long sum=0;
	int ans=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int l=1;l<=n;l++){
		if(l>r)r=l,sum=0;
		while(r<n && sum-1LL*r*a[r]+1LL*r*a[r+1]<=m){
			sum=sum-1LL*a[r]*r+1LL*a[r+1]*r;
			r++;
		}
		ans=max(ans,r-l+1);
		sum=sum-a[r]+a[l];
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
