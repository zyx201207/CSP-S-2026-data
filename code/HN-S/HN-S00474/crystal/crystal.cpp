#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500010],s[500010];
int check(int q){
	int mn=1e18;
	for(int i=q;i<=n;i++){
		mn=min(mn,s[i]-s[i-q]);
	}
	return mn;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i!=1)a[i]=a[i]-a[i-1];
		s[i]=a[i]*(i-1)+s[i-1];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		int midd=check(mid);
		if(midd<=m)l=mid;
		else r=mid;
	}
	cout<<r<<endl;
	return 0;
}
