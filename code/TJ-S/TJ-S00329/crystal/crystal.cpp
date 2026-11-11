#include<bits/stdc++.h>
using namespace std;
long long a[1000007];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
	long long l=1,r=1,sum=0,cnt=1;
	while(l<=n && r<=n){
		if(sum<=m){
			ans=max(ans,r-l+1);
			r++;
			sum+=cnt*(a[r]-a[r-1]);
			cnt++;
		}
		else{
			cnt--;
			sum-=a[r]-a[l];
			l++;
		}
	}
	cout << ans;
	return 0;
} 
