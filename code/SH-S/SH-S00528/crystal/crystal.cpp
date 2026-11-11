#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l=1,r=1,s[500005],ans,temp;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		s[i+1]=s[i]+i*(a[i+1]-a[i]);
	while(r<=n){
		temp=s[r]-s[l]-(l-1)*(a[r]-a[l]);
		if(temp>m){
			l++;
			continue;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout << ans;
	return 0;
}
