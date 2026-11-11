#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],f[500005];
bool check(long long len){
	for(int i=1;i<=n-len+1;i++){
		if(a[i+len-1]*len-(f[i+len-1]-f[i-1])<=m)return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	stable_sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	long long l=1,r=n,ans=1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
