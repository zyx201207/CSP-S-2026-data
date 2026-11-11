#include<bits/stdc++.h>
using namespace std;
int m,n;
long long maxn=0;
long long a[200001],dp[20][2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(i!=j){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	cout<<0;
	return 0;
} 
