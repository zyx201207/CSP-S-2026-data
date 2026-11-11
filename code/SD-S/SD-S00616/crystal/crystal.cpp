#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=5e5+9;
int n,m;
int a[N];
int sum[N];
int ans;

int calc(int l,int r){
	int res=(r-l+1)*a[r];
	res-=(sum[r]-sum[l-1]);
	return res;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1;
	for(int r=1;r<=n;r++){
		while(l<=r&&calc(l,r)>m)l++;
		if(l<=r)ans=max(ans,r-l+1);
	}
	cout<<ans;
}
