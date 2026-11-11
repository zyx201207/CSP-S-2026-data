#include <bits/stdc++.h>
using namespace std;

int n;
long long m,a[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,ans=0;
	long long sum=0;
	while(l<=r && r<=n){
		if(sum<=m){
			ans=max(ans,r-l+1);
			sum+=(a[r+1]-a[r])*(r-l+1);
			r++;
		}
		else{
			sum-=a[r]-a[l];
			l++;
		}
	}
	cout<<ans;
	return 0;
}
