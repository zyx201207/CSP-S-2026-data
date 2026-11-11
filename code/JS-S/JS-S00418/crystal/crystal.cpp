#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
vector<ll> a(N,0);
int n;
ll m;

bool judge(int mid){
	mid--;
	ll cnt=0;
	for(int i=0;i<mid;i++){
		cnt+=llabs(a[i]-a[mid]);
		if(cnt>m) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a.begin(),a.end());
	int ans=0;
	int left=0,right=n;
	while(left<=right){
		int mid=(left+right)/2;
		if(judge(mid)){
			ans=mid;
			left=mid+1;
		}
		else right=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
