#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int a[500005];
vector<int>b[50005];
int qqq(int q){
	for(int i=1;i<4;i++){
		if(b[i][q-1]<=m){
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			b[i].push_back(abs(a[i]-a[j]));
		}
	}
	int l=0,r=n;
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(qqq(mid)==1){
			l=mid+1;
			ans=mid;
		}else {
			r=r-1;
			ans=mid;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

