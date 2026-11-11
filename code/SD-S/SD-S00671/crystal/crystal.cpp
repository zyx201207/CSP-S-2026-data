#include<bits/stdc++.h>
using namespace std;
#define N 500100
#define endl "\n"
#define mod 998244353
int n,m;
vector<long long>a(N),sum(N);
int ans=0;
bool cmp(int q,int w){
	return q>w;
}
bool check(int mid){
	for(int l=1;l<=n-mid+1;l++){
		int r=min(l+mid-1,n);
		long long use=mid*a[l]-(sum[r]-sum[l-1]);
		if(use<=m)return 1;
	}
	return 0;
}
void _find(){
	int l=0,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n,cmp);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	_find();
	cout<<ans;
	return 0;
}

