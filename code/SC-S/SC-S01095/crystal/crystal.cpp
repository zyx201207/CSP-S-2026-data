#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1e3;
int n,m,a[N],l=1,r=1,hf,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	hf=0;
	while(r<=n){
		hf+=(a[r]-a[r-1])*(r-l);
		while(hf>m){
			hf-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
