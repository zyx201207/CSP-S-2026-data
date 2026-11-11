#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
void dfs(int x,long long y){
	if(x==m){
		ans=max(ans,y);
		return ;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i+1,y&a[i]);
	}
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2){
		ans=0;
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(i,a[i]);
		}
		cout<<ans;
		return 0;
	}
	ans=a[n];
	for(int i=n;i>=n-m;i++){
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
