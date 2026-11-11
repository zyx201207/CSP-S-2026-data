#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+9;
int n,m,a[N],sum,cnt,ans;
signed main(){
#ifndef DEBUG
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	int r=1;
	for(int l=1;l<=n;l++){
		while(r<=n&&sum+a[l]-a[r]<=m){
			sum+=a[l]-a[r];
			r++;
			cnt++;
		}
#ifdef DEBUG
		cout<<"["<<l<<","<<r<<"]\n";
#endif
		ans=max(ans,cnt);
		sum-=(a[l]-a[l+1])*(r-l);
		cnt--;
	}
	cout<<ans<<endl;
	return 0;
}
