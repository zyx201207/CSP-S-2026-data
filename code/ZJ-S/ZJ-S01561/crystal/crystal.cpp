#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n;
ll m,mx=LLONG_MIN,a[500010],s[500010];

bool check(int x){
	ll amn=LLONG_MAX;
	for(int i=x;i<=n;i++){
		amn=min(amn,s[i]-s[i-x]-(mx-a[i])*x);
	}
	return amn<=m;
}

int ans(int l,int r){
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=a[n]-a[i];
		s[i]+=s[i-1];
	}
	cout<<ans(1,n);
	return 0;
}
