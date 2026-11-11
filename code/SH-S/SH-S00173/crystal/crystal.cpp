#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009];
long long check(long long x){
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		if(i>=x){
			cnt-=a[i-x];
			if(cnt+m>=a[i]*x) return 1;
		}
	}
	return 0;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=0,r=n;
	//for(int i=0;i<=10;i++) cout<<check(i)<<'\n';
	
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	
	cout<<l<<'\n';
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;//cin>>T;
	while(T--) solve();
}
/*
5 5 
1 2 4 8 9
*/