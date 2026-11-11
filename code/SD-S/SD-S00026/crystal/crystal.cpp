#include<bits/stdc++.h>
using namespace std;
int n,m,ans = -1;
long long shu[1000500],sum[1000500];
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>shu[i];
		
	}
	sort(shu+1,shu+n+1);
	for(int i = 1;i<=n;i++){
		sum[i] = shu[i]+sum[i-1];
		
	}
	for(int l = 1,r = 1;l<=n;l++){
		while(r<n&&(shu[r+1]*(r+1-l+1)-sum[r+1]+sum[l-1]<=m)){
			r++;
		}
		if(shu[r]*(r-l+1)-sum[r]+sum[l-1]<=m){
			ans = max(r-l+1,ans);
		}
	}
	cout<<ans;

	return 0;
}

