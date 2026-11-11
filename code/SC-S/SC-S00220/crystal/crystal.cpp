#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],pre[N];
int n;
ll m;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=1;i<=n;++i) {
		int l=1,r=i,k;
		while(l<=r) {
			int mid=l+r>>1;
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) r=mid-1,k=mid;
			else l=mid+1;
		}
		ans=max(ans,i-k+1);
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/