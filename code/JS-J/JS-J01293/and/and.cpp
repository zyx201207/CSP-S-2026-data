#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100300],maxx;
void dfs(long long deep,long long sum,long long geshu){
	if(geshu==m){
		maxx=max(maxx,sum);
		return;
	}//m-geshu<n-deep
	if(deep==n){
		return;
	}
	if(geshu<1){
		dfs(deep+1,a[deep+1],geshu+1);
		dfs(deep+1,sum,geshu);
	}
	else if(geshu>=1){
		dfs(deep+1,a[deep+1]&sum,geshu+1);
		dfs(deep+1,sum,geshu);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n>=10000){
		long long minn;
		cin>>a[1];
		minn=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			minn=min(minn,a[i]);
		}
		cout<<minn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<maxx;
	return 0;
}
