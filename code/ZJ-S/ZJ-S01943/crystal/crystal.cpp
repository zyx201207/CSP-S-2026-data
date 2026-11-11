#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;


namespace ImTrying{
	int n,m;
	int a[N];
	int p[N];
	bool check(int i,int k){
		return k*a[i]-(p[i]-p[i-k])<=m;
	}
	void work(){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
		int ans=0;
		for(int i=n;i>=1;i--){
			//int cost=0;
			//bool f=1;
			//for(int j=i-1;j>=1;j--){
			//	cost+=a[i]-a[j];
			//	if(cost>m){
			//		f=0;
			//		ans=max(ans,i-j);
			//		break;
			//	}
			//}
			//if(f) ans=max(ans,i);
			int l=1,r=i;
			while(l<=r){
				int mid=(l+r)>>1;
				if(check(i,mid)){
					ans=max(ans,mid);
					l=mid+1;
				}
				else r=mid-1;
				//cout<<i<<":"<<mid<<"\n";
			}
		}
		cout<<ans;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ImTrying::work();
	return 0;
}
