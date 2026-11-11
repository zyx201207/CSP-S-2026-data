//luoqiyuan xianshitieyizhongxue SN-J00663
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
int ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			int minn=min(a[l],a[r]);
			ans+=minn;
			a[l]-=minn,a[r]-=minn;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
		else{
			int minn=min(a[l],a[r]);
			a[l]-=minn,a[r]-=minn;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
