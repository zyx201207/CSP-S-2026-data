#include <bits/stdc++.h>
#define int long long
#define N 500008
using namespace std;
int n,m,ans;
int a[N];
bool check(int x){
	int sum=0;
	for(int i=1;i<=x;i++){
		sum+=a[x]-a[i];
	}
	if(sum<=m){return true;}
	for(int i=2;i<=n-x+1;i++){
		sum-=(a[i+x-1]-a[i]);
		sum+=(x-1)*(a[i+x-1]-a[i+x-2]);
		if(sum<=m){return true;}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,r=n,res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			res=mid;
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	cout<<res<<endl;
	return 0;
}

