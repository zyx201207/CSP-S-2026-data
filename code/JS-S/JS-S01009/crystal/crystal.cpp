#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[500005],s[500005];

int sum(int x,int y){
	return (y-x)*a[y]-s[y-1]+s[x-1];
}

bool check(int x,int y){
	if(sum(x,y)<=m){
		return true;
	}else{
		return false;
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=2;
	while(l<r && r<=n){
		if(check(l,r)){
			ans=max(ans,r-l+1);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	
	return 0;
}
