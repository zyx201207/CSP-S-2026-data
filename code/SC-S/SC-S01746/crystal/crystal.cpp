#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
void solve(){
	int mx=-1e9;
	for(int i=2;i<=n;i++){
		long long sum=0;
		long long cnt=1;
		for(int j=i-1;j>=1;j--){
			if(sum+(a[i]-a[j])<=m){
				sum+=(a[i]-a[j]);
				cnt++;
			}
			else{
				break;
			}
		}
		if(cnt>mx){
			mx=cnt;
		}
	}
	cout<<mx;
	return;
}
void solve2(){
	long long d=a[n]-a[n-1];
	for(int i=2;i<=n;i++){
		b[i]=i*(i-1)/2;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(b[i]>m){
			ans=i-1;
		}
		else if(b[i]==m){
			ans=i;
		}
	}
	cout<<ans;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		solve();
	}
	else{
		solve2();
	}
	return 0;
}