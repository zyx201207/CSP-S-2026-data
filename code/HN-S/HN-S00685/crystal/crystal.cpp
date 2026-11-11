#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N];
vector<int> idx;
bool check(int x){
	if(x>n) return false;
	idx.clear();
	int cnt=1e18,mn=1e18;
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		if(a[j]-a[i-1]<mn){
			mn=a[j]-a[i-1];idx.clear();
			idx.push_back(i);
		}
		else if(a[j]-a[i-1]==mn) idx.push_back(i);
	}
	for(auto e: idx){
		int num=0;
		for(int i=e;i<e+x-1;i++){
			num+=a[e+x-1]-a[i];
		}
		cnt=min(cnt,num);
	}
//	cout<<cnt<<"\n";
	return cnt<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=0,r=n+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
//Oct31==Dec25?
