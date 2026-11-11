#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=5e5+5;
const ll inf=(1LL<<60);
int n,ans=-1;
ll m,a[N],pre[N];
bool check(int p,int k){
	return (ll)k*a[p]-pre[p-1]+pre[p-k-1]<=m;
}
int search(int p){
	int l=0,r=p-1;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(p,mid))l=mid;
		else r=mid-1;
	}
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	a[n+1]=inf;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])continue;
		ans=max(ans,search(i)+1);
	}
	cout<<ans;
	return 0;
}
