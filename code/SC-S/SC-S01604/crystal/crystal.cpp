#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,arr[N],s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+arr[i];
	int res=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if((i-mid+1)*arr[i]-(s[i]-s[mid-1])<=m) r=mid;
			else l=mid;
		}
		if((i-l+1)*arr[i]-(s[i]-s[l-1])<=m) res=max(res,i-l+1);
		else res=max(res,i-r+1);
	}
	cout<<res<<'\n';
	return 0;
}