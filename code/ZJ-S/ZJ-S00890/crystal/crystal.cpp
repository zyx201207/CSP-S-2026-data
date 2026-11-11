#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long n,m,a[500010],ans=1,l=1,r=1,sum=0;
int main(){
	fast;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(r<=n&&sum<=m){
		r++;
		if(r>n){
			r=n;
			break;
		}
		sum+=(r-1)*(a[r]-a[r-1]);
	}
	if(sum>=m){
		sum-=(r-1)*(a[r]-a[r-1]);
		r--;
	}
	ans=r-l+1;
	while(l<=n&&r<=n){
		sum-=a[r]-a[l];
		l++;
		while(r<=n&&sum<=m){
			r++;
			if(r>n){
				r=n;
				break;
			}
			sum+=(r-l)*(a[r]-a[r-1]);
		}
		if(sum>=m){
			sum-=(r-l)*(a[r]-a[r-1]);
			r--;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
