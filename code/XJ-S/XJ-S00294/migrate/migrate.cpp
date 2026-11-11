#include<bits/stdc++.h>
using namespace std;
int n;
long long d,a[2000005],dp[2000005];
int bound(long long x,int y){
	int l=1,r=y,ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]>=x){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
//bool check(int i){
//	int ans=0;
//	for(int j=bound(a[i]-d,i);j<i;j++){
//		for(int k=bound(a[j]-d,j);k<j;k++){
//			if()ans++;
//		}
//	}
//	return ans==2;
//}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			dp[i]=0;
		}
		long long ans=0;
		for(int i=3;i<=n;i++){
			//if(check(i))ans++;
			int j=bound(a[i]-d,i);
			if(j==i-1)dp[i]=dp[i-1];
			else{
				int ans=0;
				while(j<i){
					if(bound(a[j+1]-d,j+1)==bound(a[j]-d,j))
					j++;
				}
			}
		}
		cout<<0<<'\n';
	}
	return 0;
}/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
