#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N],b[N];
int pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
		b[i]=a[i];
	unique(b+1,b+n+1);
	int now=1;
	for(int i=1;i<=n;i++){
		if(a[i]==b[now]) a[i]=now;
		else a[i]=++now;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]) continue;
		int l=0,r=i+1;
		while(l+1<r){
			int mid=(l+r)/2ll;
			if(b[a[i]]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
