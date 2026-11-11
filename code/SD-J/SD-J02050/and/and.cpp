#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10;
const int INF=-0x3f3f3f3f3f3f3f3f;
int n,m;
int a[N],dp[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		int ans=INF;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=INF;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)
					continue;
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(n<=20){
		int ans=INF;
		for(int i=0;i<1<<n;i++){
			int cnt=0,x=-1;
			for(int j=0;j<n;j++){
				if(i&(1<<j)){
					if(x==-1)
						x=a[j+1];
					else
						x=(x&a[j+1]);
					cnt++;
				}
			}
			if(cnt==m)
				ans=max(ans,x);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
