#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans=0,l=1,r=1,mid;
bool check(long long x){
	long long res=0;
	for(long long i=1;i<=x-1;i++){
		res+=i*(a[i+1]-a[i]);
	}
	if(res<=m) return 1;
	for(long long i=x;i<=n-1;i++){
		res=res-(a[i]-a[i-x+1])+(x-1)*(a[i+1]-a[i]);
		if(res<=m) return 1;
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
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=1){
		cout<<max(0LL,n);
		return 0;
	}
	sort(a+1,a+n+1);
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}