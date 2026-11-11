#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long dis[15];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;cin>>n>>m;
	if(m==n){
		long long cnt;cin>>cnt;
		for(long long i=2;i<=n;i++){
			long long x;cin>>x;
			cnt=cnt&x;
		}
		cout<<cnt;
		return 0;
	}
	if(m==1){
		long long mx=0;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	int t=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<4)t++;
	}
	if(t==n){
		for(int i=1;i<=n;i++){
			dis[a[i]]++;
		}
		if(m<=dis[3]){
			cout<<3;
			return 0;
		}
		if(m<=(dis[3]+dis[2])){
			cout<<2;
			return 0;
		}
		if(m<=(dis[3]+dis[1])){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	long long ans=INT_MAX;
	for(int i=n;i>=1&&m;i--){
		ans=min(ans,a[i]);
		m--;
	}
	cout<<ans;
}
