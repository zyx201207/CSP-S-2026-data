#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1,sum=0,res=1;
	while(r<=n&&l<=r){
		r++,sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m&&l<r) sum-=a[r]-a[l],l++;
		res=max(res,r-l+1);
	}
	cout<<res;
	return 0;
} 