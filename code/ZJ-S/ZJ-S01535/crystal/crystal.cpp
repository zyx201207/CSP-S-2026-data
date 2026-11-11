#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[514514];
int sum[514514];
int answer;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[n]-a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(sum[i]-sum[mid-1]-(i-mid+1)*(a[n]-a[i])<=m){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}
		answer=max(answer,i-ans+1);
	}
	cout<<answer;
	return 0;
}