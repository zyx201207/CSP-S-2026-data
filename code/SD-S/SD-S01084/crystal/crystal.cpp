#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[510000],pre[510000];
int n,m;
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		if(a[i+x-1]*x-(pre[i+x-1]-pre[i-1])<=m)return 1;
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=0,r=2e18,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
