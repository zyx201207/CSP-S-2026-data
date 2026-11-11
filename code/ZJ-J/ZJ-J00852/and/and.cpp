#include<bits/stdc++.h>
using namespace std;
long long dp[200005];
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long mh=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mh=max(mh,a[i]);
	}
	if(n<=3000){
		sort(a,a+n);
		for(int i=0;i<=m;i++){
			dp[i]=0;
		}
		dp[0]=(1ll<<31)-1;
		for(int i=0;i<n;i++){
			for(int j=m;j>0;j--){
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
		}
		for(int i=0;i<=m;++i){
			
		}
		cout<<dp[m];
		return 0;
	}
	if(mh<=4){
		int cnt[5]={0,0,0,0,0};
		for(int i=0;i<n;i++){
			cnt[a[i]]++;
		}
		if(cnt[4]>=m){
			cout<<4;
			return 0;
		}
		if(cnt[3]>=m){
			cout<<3;
			return 0;
		}
		if(cnt[3]+cnt[2]>=m){
			cout<<2;
			return 0;
		}
		if(cnt[3]+cnt[1]>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	if(mh<=1024){
		int cnt[1025]={};
		for(int i=0;i<n;i++){
			cnt[i]++;
		}
		for(int i=mh;i>0;i--){
			if(cnt[i]>=m){
				cout<<i;
				return 0;
			}
		}
	}
	else {
		int cnt[35];
		for(int i=0;i<n;++i){
			int l=0;
			if(a[i]==1){
				cnt[1]++;
				continue;
			}
			while((1<<l)<a[i])l++;
			cnt[l]++;
		}
		int sum=0;
		for(int i=35;i>=0;i++){
			sum+=cnt[i];
			if(sum>=m){
				cout<<(1<<i)-1;
				return 0;
			}
		}
	}
}
