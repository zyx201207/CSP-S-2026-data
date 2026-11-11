#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int ans;
int a[N];
int c[N];
int s[N];
int check(int x){
	int mn=1e18;
	for(int i=x;i<=n;i++){
		mn=min(mn,(s[i]-s[i-x])-x*c[i]);
	}
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[n]-a[i];
		s[i]=s[i-1]+c[i];
		
	}
	
	int l=1;
	int r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	
	return 0;
}

