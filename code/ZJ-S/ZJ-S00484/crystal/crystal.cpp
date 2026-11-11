#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll>a,sum;
ll ans;
ll get(int i,int j){
	return abs(sum[j]-sum[i-1]-a[j]*(j-i+1));
}
int main(){
	int n;
	ll m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0){
		map<ll,int>mp;
		for(int i=1,x;i<=n;i++){
			cin>>x,mp[x]++;
		}ans=(*mp.begin()).second;
		cout<<ans*(ans!=1)<<'\n';
		return 0;
	}a.resize(n+1),sum.assign(n+1,0);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int i=1,j=1;
	while(i<=j&&j<=n){
		while(i-1>=1&&get(i,j)<m)i--;
		while(i+1<=n&&get(i,j)>m)i++;
		ans=max(ans,j-i+1ll);
		j++;
	}cout<<ans*(ans!=1)<<'\n';
	return 0;
}
