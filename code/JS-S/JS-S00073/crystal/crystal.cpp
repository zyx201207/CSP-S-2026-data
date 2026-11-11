#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],s[N];
vector<pair<int,int>> v;
vector<int> start;
bool check(int mid){
	for(int i=2; i<v.size(); ++i){
		if(start[i]+v[i].second-mid<=0) continue;
		int sum=0;
		sum+=(mid-v[i].second)*v[i].first-s[start[i]-1]+s[start[i]+v[i].second-mid-1];
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i) s[i]=s[i-1]+a[i];
	v.push_back({0,0});
	start.push_back(0);
	int cnt=0;
	for(int i=1; i<=n; ++i){
		if(a[i]!=a[i+1] || i==n){
			v.push_back({a[i],i-cnt});
			start.push_back(cnt+1);
			cnt=i;
		}
	}
	int ans=0,left=1,right=n;
	for(int i=1; i<v.size(); ++i){
		left=max(left,v[i].second);
	}
	while(left<=right){
		int mid=(left+right)/2;
		if(check(mid)){
			left=mid+1;
			ans=mid;
		}
		else right=mid-1;
	}
	cout<<ans;
	return 0;
}
