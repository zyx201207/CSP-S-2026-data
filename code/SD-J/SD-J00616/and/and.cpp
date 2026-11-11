#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n,m;
int a[1000005];
int maxx=0;
int dp[1000][1000];
void dfs(int k,int sum,int w){
	if(k==m){
		maxx=max(maxx,sum);
		return;
	}
	if(w==n){
		return;
	}
	dfs(k+1,sum&a[w+1],w+1);
	dfs(k,sum,w+1);
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;i++){
			dfs(1,a[i],1);
		}
		cout<<maxx;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
		return 0;
	}
	int maxx1=1;
	for(int i=1;i<=n;i++){
		maxx1=max(maxx1,a[i]);
	}
	if(maxx1<4){
		if(maxx1==3){
			cout<<3;
		}
		if(maxx1==2&&m==2){
			bool f=1;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					f=0;
					break;
				}
			}
			if(f==0){
				cout<<3;
			}else{
				cout<<2;
			}
		}else{
			cout<<maxx1;
		}
	}else{
		maxx=0;
	}
	cout<<maxx;
	return 0;
}
