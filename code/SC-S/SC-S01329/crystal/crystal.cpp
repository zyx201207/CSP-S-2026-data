#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,a[500050],d[500050];

bool check(int mid){
	for (int i=mid;i<=n;i++){
		ll sum=0,cnt=mid-1;
		bool p=1;
		for (int j=i-1;j>i-mid;j--){
			if (sum+d[j]*cnt>m){
				p=0;
				break;
			}	
			sum+=d[j]*cnt;
			cnt--;
		}
		if (p) return true;
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if (check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}