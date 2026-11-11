#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans;
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(1){
		if(l>=r)break;
		if(c[l]!=c[r]){
			int cnt=min(a[l],a[r]);
			ans+=cnt;
			a[l]-=cnt;
			a[r]-=cnt;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}else{
			int cnt=min(a[l],a[r]);
			a[l]-=cnt;
			a[r]-=cnt;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
