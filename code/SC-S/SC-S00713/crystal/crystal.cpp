#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
long long b[500005];
bool check(long long p){
	for(int i=p;i<=n;i++){
		long long sum=b[i]-b[i-p];
		if(a[i]*p-sum<=m)return 1;
	}
	return 0; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}