#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		int x=0;
		for(int j=1;j<=i;j++){
			x+=a[j];
		}
		if(a[i]*i<=x+m){
			ans=max(ans,i);
		}
	}
	cout<<ans;
	
	return 0;
}
