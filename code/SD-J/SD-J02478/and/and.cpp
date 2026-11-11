#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200010];
int bin[200010];
int b[200010];
int maxx=LLONG_MIN;
int cnt;
bool check(){
	bin[1]=2;
	for(int i=2;i<=30;i++){
		bin[i]=bin[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		if(*lower_bound(bin+1,bin+31,a[i]+1)!=a[i]+1){
			return false;
		}
	}
	return true;
}
bool check2(){
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]+1){
			return false;
		}
	}
	return true;
}
void dfs(int x,int p){
	if(x==m+1){
		int ans=b[1];
		for(int i=2;i<=n;i++){
			ans&=b[i];
		}
		maxx=max(maxx,ans);
	}
	for(int i=p+1;i<=/*n-m+x+1*/n;i++){
		b[++cnt]=a[i];
		dfs(x+1,i);
		cnt--;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);	
			}
		} 
		cout<<maxx;
		return 0;
	}
	if(check()){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	if(check2()){
		cout<<n-m;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0);
	cout<<maxx;
	return 0;
} 
