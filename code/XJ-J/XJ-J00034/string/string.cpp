#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,cnt=0;
	while(l<r){
		if(c[l]==c[r]){
			int minn=min(a[l],a[r]);
			a[l]-=minn;
			a[r]-=minn;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}else{
			int minn=min(a[l],a[r]);
			cnt+=minn;
			a[l]-=minn;
			a[r]-=minn;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
		}
	}
	cout<<cnt;
	return 0;
}
