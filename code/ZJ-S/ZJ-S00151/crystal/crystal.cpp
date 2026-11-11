#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	int now=0,use=0,hg=0,hd=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1)hg=a[i],now=1,hd=1;
		else {
			use+=(a[i]-hg)*now;
			++now;
			hg=a[i];
			while(use>m){
				use-=(hg-a[++hd]);
				--now;
			}
		}
		ans=max(ans,now);
	}
	cout<<ans;
	return 0;
} 
