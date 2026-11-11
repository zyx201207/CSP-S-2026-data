#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+1];
	int dp[n+1];
	int ppp;
	int pppn;
	int max_ooo=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			pppn=a[i];
		}
		pppn&=a[i];
		max_ooo=max(max_ooo,a[i]);
	}
	if(m==2){
		int ma=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
		return 0;
	}
	if(n==m){
		cout<<pppn;
		return 0;
	}
	if(m==1){
		cout<<max_ooo;
		return 0;
	}
	if(m==n-1){
		int ma=-1;
		for(int i=1;i<=n;i++){
			int pp=a[1];
			if(i==1){
				pp=a[2];
			}
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				pp&=a[j];
			}
			ma=max(ma,pp);
		}
		cout<<ma;
		return 0;
	}
	
	ppp=a[1];
	for(int i=1;i<=m;i++){
		ppp&=a[i];
	}
	a[m]=ppp;
	cout<<a[n];
	return 0;
}
