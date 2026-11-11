#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],maxn;
bool check(long long l,long long r){
	if(s[r]-s[l-1]+m>=a[r]*(r-l+1)) return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		long long l=i,r=n;
		while(l<r-1){
			long long mid=(l+r)/2;
			if(check(i,mid)){
				l=mid;
			}
			else{
				r=mid-1;
			}
		}
		maxn=max(maxn,l-i+1);
	}
	cout<<maxn;
	return 0;
}



