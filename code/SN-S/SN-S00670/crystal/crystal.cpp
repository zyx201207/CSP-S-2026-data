#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+7;
int n,m;
int a[N];
int sum[N];
int check(int id,int s){
	int geshu=s-id;
	int zonghe=geshu*a[s]-sum[s-1]+sum[id-1];
	return zonghe;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		int l=1,r=i-1;
		int ansid=-1;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(check(mid,i)>m) l=mid+1;
			else{
				r=mid-1;
				ansid=mid;
			}
		}
		if(ansid==-1) continue;
		ans=max(i-ansid+1,ans);
	}
	cout<<ans;
	return 0;
} 
