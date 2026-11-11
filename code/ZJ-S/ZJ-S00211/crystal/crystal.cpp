#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+5;
int n,m,ans;
array<int,N> a;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	clock_t Start=clock();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a.begin()+1,a.begin()+1+n);
	int res=0;
	for(int r=1,l=1;r<=n;r++){
		res+=a[r];
		while(l<=r&&(r-l+1)*a[r]-res>m)
			res-=a[l],l++;
		// cout<<(r-l+1)*a[r]-res<<' '<<l<<' '<<r<<' '<<endl;
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	cerr<<(double)(clock()-Start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
/*
14:54

haru
*/