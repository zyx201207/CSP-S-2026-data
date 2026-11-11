#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace Solver_T1{
	ll a[1000005],pr[1000005];
	void Recall(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0);cin.tie(0);
		int n;
		ll m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)pr[i]=pr[i-1]+a[i];
		int ans=0;
		for(int i=1;i<=n;i++){
			int l=1,r=i-1,p=i;
			while(l<=r){
				int mid=l+r>>1;
				if((a[i]*(i-mid+1))-(pr[i]-pr[mid-1])<=m)r=mid-1,p=mid;
				else l=mid+1;
			}
			ans=max(ans,i-p+1);
		}
		cout<<ans<<'\n';
	}
}
int main(){
	Solver_T1::Recall();
}

/*
我 常常 追忆 过去。

There's no point to "recall".
*/ 
