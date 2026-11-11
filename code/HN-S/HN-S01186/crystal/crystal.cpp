#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m,a[500010],sum[500010],sum2[500010]; 
bool check(int x,int k){
	int r=sum[k]-sum[x];
	int y=sum2[k]-sum2[x];
	return y-(x-1)*r<=m;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(a[i]-a[i-1]);
		sum2[i]=sum2[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid-1;
			else l=mid+1;
		}
		maxn=max(maxn,i-r);
	}
	cout<<maxn;
	return 0;
} 
