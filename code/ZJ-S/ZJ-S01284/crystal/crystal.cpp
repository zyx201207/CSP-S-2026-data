#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
int n;
ll m;
ll a[N];
bool check(int limit){
	ll sum=0,target=a[limit]*limit;
	for(int i=1;i<=limit;i++)sum=sum+a[i];
	if(target-sum<=m)return true;
//	cout<<1<<" "<<limit<<" "<<target-sum<<"\n";
	for(int i=2;i+limit-1<=n;i++){
		sum=sum-a[i-1]+a[i+limit-1];
		target=a[limit+i-1]*limit;
		if(target-sum<=m)return true;
//		cout<<i<<" "<<limit+i-1<<" "<<target-sum<<"\n";
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("crystal4.in","r",stdin);
//	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n;
	while(l<r){
//		cout<<l<<","<<r<<"\n";
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
//	for(int i=1;i<=n;i++){
//		check(i),cout<<"\n";
//	}
//	cout<<a[313324]<<"\n"<<check(313324)<<"\n";
//	cout<<a[313325]<<"\n"<<check(313325)<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/