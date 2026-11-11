#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	ll m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	int lo=1,hi=n;
	while(lo<hi){
		int mid=(lo+hi+1)>>1;
		ll sum=0;
		bool flag=0;
		for(int i=1;i<=mid-1;i++)sum+=a[i];
		for(int i=mid;i<=n;i++){
			sum+=a[i];
			if(a[i]*mid-sum<=m) flag=1;
			sum-=a[i-mid+1];
		}
		if(flag) lo=mid;
		else hi=mid-1;
	}
	cout << lo;
	return 0;
}