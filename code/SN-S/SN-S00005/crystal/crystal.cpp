//SN-S00005 BZOI2729 Cl_baseRF 
#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long n,m;
int dlt[500050];
long long pgs(int x,int id){
	int ans0 = 0,mt = m;
	for(int i = 1;i<=n;i++){
		dlt[i] = a[i]-x;
	}
	for(int i = id;i>=1;i--){
		if(mt<0)break;
		if(mt+dlt[i]>0){
			mt+=dlt[i];
			ans0++;
		}
	}
	return ans0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long ans = -1;
	cin>>n>>m;
	bool flag = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])flag = 0;
		}
	}
	if(flag==0){
		sort(a+1,a+n+1); 
		for(int i = 1;i<=n;i++){
			long long ans0 = pgs(a[i],i);
			if(ans0>ans){
				ans = ans0;
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		int bsc = a[n];
		int id_bsc = n;
		for(int i = 1;i<=n;i++){
			dlt[i] = a[i] - bsc;
		}
		for(int i = id_bsc;i>=1;i--){
			if(dlt[i]==0){
				ans++;
			}
			if(m<0)break;
			if(m+dlt[i]>=0){
				ans++;
				m+=dlt[i];
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
