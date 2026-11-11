#include<bits/stdc++.h>
using namespace std;
namespace Crystal{
	const int MAXN=5e5+10;
	int n;
	long long m;
	long long a[MAXN];
	int ans;
	bool check(int k){
		long long sum=0,res=0;
		for(int i=2;i<=k;i++)
			sum+=(i-1)*(a[i]-a[i-1]);
		res=sum;
		for(int i=k+1;i<=n;i++){
			sum-=(a[i-1]-a[i-k]);
			sum+=(a[i]-a[i-1])*k;
			res=min(res,sum);
		}
		return res<=m;
	}
	void work(){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(mid)){
				ans=mid;
				l=mid+1;
			}
			else
				r=mid-1;
		}
		cout<<ans;
		return;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	Crystal::work();
	return 0;
}
