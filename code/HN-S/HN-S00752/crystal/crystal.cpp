#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500003],s[500003],maxn;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
				r=mid;
			}else{
			    l=mid+1;	
			}
		}
		if(a[i]*(i-l)-(s[i-1]-s[l-1])<=m){
			maxn=max(maxn,i-l+1);
		}
		s[i]=s[i-1]+a[i];
	}
	cout<<maxn;
	return 0;
} 
