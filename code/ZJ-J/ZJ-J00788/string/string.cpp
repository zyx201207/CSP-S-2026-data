#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],ans;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
//		cout<<ans<<'\n';
		if(c[l]==c[r]){
			int cnt=min(a[l],a[r]);
			a[l]-=cnt;
			a[r]-=cnt;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}else{
			int cnt=min(a[l],a[r]);
			ans+=cnt;
			a[l]-=cnt;
			a[r]-=cnt;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
//		cout<<l<<" "<<r<<'\n';
	}
	cout<<ans;
}