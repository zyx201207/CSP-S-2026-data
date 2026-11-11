#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],dp[N],sum[N],b[N];
int n,m;
map<int,int> mp;
bool cmp(int a,int b){
	return mp[a]>mp[b];
}
int maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				int ans=a[i];
				ans&=a[j];
				maxn=max(maxn,ans);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int maxc=-1;
		for(int i=1;i<=n;i++){
			int ans;
			if(i==1){
				ans=a[2];
				for(int j=3;j<=n;j++){
					ans&=a[j];
				}
			}
			else{
				ans=a[1];
				for(int j=2;j<=n;j++){
					if(j==i) continue;
					ans&=a[j];
				}
			}
			maxc=max(maxc,ans);
		}
		cout<<maxc;
		return 0;
	}
	memcpy(b,a,sizeof a);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			if(b[i]&1) mp[a[i]]++;
			b[i]>>=1;
		}
	}
	sort(a+1,a+n+1,cmp);
	maxx=a[1];
	for(int i=2;i<=m;i++){
		maxx&=a[i];
	}
	cout<<maxx;
	return 0;
}
