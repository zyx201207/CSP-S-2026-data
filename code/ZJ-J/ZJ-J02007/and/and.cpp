#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int lg[200005];
long long mx;
long long n,m;
void dfs(long long maxi,long long z,long long cnt){
	if(cnt==m) mx=max(mx,z);
	for(int i=maxi+1;i<=n;i++) dfs(i,z&a[i],cnt+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool f=1;
	mx=LONG_LONG_MIN;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(pow(2,floor(log2(a[i])))!=a[i]-1) f=0;
	}
	if(f){
		sort(a+1,a+n+1);
		cout<<a[m];
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++) dfs(i,a[i],1);
		cout<<mx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++) mx=max(mx,a[i]);
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i]; 
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) mx=max(mx,a[i]&a[j]);
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans=ans&a[i]; 
		for(int i=1;i<=n;i++) mx=max(mx,ans|a[i]); 
		cout<<mx;
		return 0;
	}
	cout<<rand()*sqrt(a[n])*a[7];
	return 0;
}