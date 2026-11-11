#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxn, b[100005];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn, a[i]);
		}
		cout<<maxn;
	}
	else if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
	}
	else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn, a[i]&a[j]);
			}
		}
		cout<<maxn;
	}
	else{
		int minn=INT_MAX;
		for(int i=1;i<=n;i++){
			minn=min(minn, a[i]);
		}
		cout<<minn;
	}
	return 0;
} 

