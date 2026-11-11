#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[200005],maxx=-1,sum[200005];
void dfs(int i,int sum,int cnt){ 
	if(i<=n){
		dfs(i+1,sum&a[i],cnt+1);
		dfs(i+1,sum,cnt);
	}
	else{
		if(cnt==m){
			maxx=max(maxx,sum);
		}	
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=a[i]&sum[i-1];
	}
	if(n<=20){
		dfs(1,2147483647,0);
		cout<<maxx;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else if(m==n){
		cout<<sum[n];
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxx=max(maxx,i&j);
			}
		}
		cout<<maxx;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			if(sum[i-1]&(sum[n]|sum[i]));
		}
	}
	else{
		int s=2147483647;
		sort(a+1,a+n+1);
		for(int i=n;i>=n-i+1;i--){
			s=s&a[i];
		}
		cout<<s; 
	}
	return 0;
} 
