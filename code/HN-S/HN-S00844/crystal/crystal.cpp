#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],s[500005],b[500005];
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int sum=0;
		bool f=0;
		for(int j=i;j>=1;j--){
			if(sum+(a[i]-a[j])>m){
				ans=max(i-j,ans);
				f=1;
				break;
			} 
			sum+=a[i]-a[j];	
		}
		if(f==0) ans=max(i,ans);
	}
	cout<<ans;
}
void solve2(){
	int ans=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+b[i]*(i-1);                                          
	}
	for(int i=n;i>=1;i--){
		if(s[i]<=m) {
			ans=i;
			break;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		solve1();
	}
	else {
		for(int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		solve2();
	}
	return 0;
}
