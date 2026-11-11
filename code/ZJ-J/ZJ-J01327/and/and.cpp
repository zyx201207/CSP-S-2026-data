#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],dp[200005],s[200005][35];
vector<int> v[35];

void dfs(){
	
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n;++i){
			for(int j=m;j>=1;--j){
				dp[j]=max(dp[j],dp[j-1]&a[i]);
			}
			dp[1]=max(dp[1],a[i]);
		}
		cout<<dp[m];
		return 0;
	}
	if(n<=2000){
		if(m==1){
			int maxx=0;
			for(int i=1;i<=n;++i)maxx=max(maxx,a[i]);
			cout<<maxx;
			return 0;
		}
		if(m==n){
			int ans=a[1];
			for(int i=2;i<=n;++i)ans&=a[i];
			cout<<ans;
			return 0;
		}
		if(m==2){
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<=n;++j){
					if(i==j)continue;
					ans=max(ans,(a[i]&a[j]));
				}
			}
			cout<<ans;
			return 0;
		}
	}
//	if(m==n-1){
//		dp[1]=a[1];
//		int ans=a[2];
//		for(int i=2;i<=n;++i){
//			dp[i]=dp[i-1]&a[i];
//			cout<<dp[i]<<' ';
//			if(i>1)ans&=a[i];
//		}
//		for(int i=1;i<n;++i){
//			ans=max(ans,dp[n]&dp[i-1]);
//		}
//		ans=max(ans,dp[n-1]);
//		cout<<ans;
//		return 0;
//	}
	int k=1,fff=0;
	while(k<=n){
		if(k==n){
			fff=1;
			break;
		}
		k*=2;
	}
	if(fff){
		int ans=a[n];
		for(int i=n-1;i>n-m;--i)ans&=a[i];
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;++i){
		sort(a+1,a+1+n);
		int k=2,cnt=0;
		while(k){
			s[i][cnt++]=a[i]%k;
			if(a[i]%k)v[k].push_back(i);
			k*=2;
			if(a[i]<k)break;
		}
		for(int i=30;i>=0;--i){
			if(v[i].size()<m)continue;
			if(v[i].size()==m){
				int ans=a[v[i][0]];
				for(int j=1;j<v[i].size();++j){
					ans&=a[v[i][j]];
				}
				cout<<ans;
				return 0;
			}
			if(v[i].size()>m){
				int p=0;
				for(int j=i-1;j>=0;--j){
					p=0;
					for(auto k:v[j]){
						if(s[k][i])p++;
					}
					if(p[j]==m){
						int ans=a[v[j][0]];
						for(auto k:v[j]){
							ans&=a[k];
						}
						cout<<ans;
						return 0;
					}
				}
			}
		}
	}
	cout<<0;
}
