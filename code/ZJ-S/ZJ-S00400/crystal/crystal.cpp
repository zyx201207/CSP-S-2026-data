#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,ans=0;
ll m,a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=a[1];
	ll sum=0;
	int l=1,r=1;
	while(r<=n){
		while(r<=n && sum+(a[r]-a[r-1])*(r-l)<=m){
			sum+=(a[r]-a[r-1])*(r-l);
			r++;
		}
		ans=max(ans,r-l);
		sum-=a[r-1]-a[l];
		l++;
	}
	cout<<ans;
	return 0;
}
