#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],c[N];
int n,m;
namespace pts5000{
	int c[N];
	void solve(){
		sort(a+1,a+n+1);
		c[1]=0;
		for(int i=2;i<=n;i++){
			c[i]=a[i]-a[i-1];
//			c[i]=c[i]+c[i-1];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int l=0;i+l<=n;l++){
				sum+=c[i+l]*l;
				if(sum>m){
					ans=max(ans,l);	
					break;
				}
			}
		}
		cout<<ans;
	}
}
namespace ptsAB{
	void solve(){
		sort(a+1,a+n+1);
		int delta=a[2]-a[1];
		int sum=0;
		for(int i=1;i<=n;i++){
			sum=sum+delta*(i-1);
			if(sum>m){
				cout<<i-1;
				break;
			}
		}
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000) pts5000::solve();
	else ptsAB::solve();
	return 0;
} 
/*
5 8
-3 -1 2 2 7
*/
