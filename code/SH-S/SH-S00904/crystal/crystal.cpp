#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n,m,x,a[500009],pre[500009];
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		if(a[j]*(j-i)-pre[j-1]+pre[i-1]<=m){
			return true;
			break;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	int l=1,r=n,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))
			l=mid+1,ans=mid;
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
/*
5 189999
1 1000 99998 99999 100000
*/
