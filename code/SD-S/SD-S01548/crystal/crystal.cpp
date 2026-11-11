#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
vector<int>a;
int n,m;
bool check(int x){
	if(x>n)return false;
	int ans=0,now=0;
	for(int i=0;i<x;i++){
		ans+=a[x-1]-a[i];
	}
	now=ans;
//	cout<<ans<<endl;
	for(int i=x;i<n;i++){
		int tmp=now;
		tmp+=(a[i]-a[i-1])*(x-1);
		tmp-=a[i-1]-a[i-x];
		now=tmp;
		ans=min(now,ans);
	}
//	cout<<ans<<endl;
	return ans<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	int l=0,r=1e18;
//	int TTL=300;
	while(l<r){
//		if(!TTL)break;
		int mid=l+(r-l+1>>1);
		if(check(mid))l=mid;
		else r=mid-1;
//		cout<<mid<<endl;
//		TTL--;
	}
	cout<<l;
//	cout<<check(315275);
	return 0;
} 
