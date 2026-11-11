#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N = 5e5+10;
long long a[N],s[N];
bool check(long long x){
	long long l=1,r=x;
	if(x==1)return true;
	while(r<=n){
		long long sum=(x-1)*a[r]-(s[r-1]-s[l-1]);
		if(sum<=m){
			return true;
		}
		r++,l++;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);	
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	long long l=1,r=n,ans=0;
	while(l<=r){
		long long mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
