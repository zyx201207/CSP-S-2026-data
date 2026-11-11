#include<bits/stdc++.h>
#define int long long
using namespace std;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()^((uint64_t)random_device{}()<<32)^(uint64_t)random_device{}());
int n,m,ans=0;
int a[500555];
inline void pred(){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n);
}
inline void calc(){
	int na=a[0],i=1,l=0,cnt=1,lft=m;
	ans=1;
	for(;i<n;++i){
		while((a[i]-na)*cnt>lft){
			lft+=na-a[l];
			--cnt;
			++l;
		}
		lft-=(a[i]-na)*cnt;
		na=a[i];
		++cnt;
		ans=max(ans,cnt);
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),
	cin.tie(0),cout.tie(0);
	//uniform_int_distribution<int>dist(0,100);
	pred();
	calc();
	return 0;
}
