#include<bits/stdc++.h>
using namespace std;
int n,a[2000005];
long long int ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){cin>>n;cin>>a[1];cout<<0;return 0;}
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]==c[r]){
			int minn=min(a[l],a[r]);
			a[l]-=minn;
			a[r]-=minn;
		}else{
			int minn=min(a[l],a[r]);
			ans+=minn;
			a[l]-=minn;
			a[r]-=minn; 
		}
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
