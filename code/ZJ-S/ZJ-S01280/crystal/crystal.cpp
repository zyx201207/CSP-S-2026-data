#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long pre[500010];
long long m;
bool check(int r,int l){
	return a[r]*(r-l+1)-(pre[r]-pre[l-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=i,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(check(mid,i)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l-i+1);
	}
	cout<<ans;
	return 0;
}
