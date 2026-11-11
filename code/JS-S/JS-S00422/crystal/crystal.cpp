#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	//for(int i=0;i<n;i++)cout<<a[i];
	int l=0,r=n-1;
	int ceshi=0;
	int ans=-1e9;
	while(l<r){
		for(int i=l;i<=r;i++){
			ceshi+=a[r]-a[i];
			}
		if(ceshi>m){
			ceshi=0;
			r--;
			}
		else if(ceshi<=m){
			ans=max(ans,r-l+1);
			break;
			l=r;
			}
	}
	l=0,r=n-1;
	ceshi=0;
	while(l<r){
		for(int i=l;i<=r;i++){
			ceshi+=a[r]-a[i];
			}
		if(ceshi>m){
			ceshi=0;
			l++;
			}
		else if(ceshi<=m){
			ans=max(ans,r-l+1);
			break;
			l=r;
			}
	}
	
	cout<<ans;
	return 0;
}
