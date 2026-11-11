#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+91; 
int n,m,w[N],sum[N];
int f(int x){
	int r=lower_bound(w+1,w+n+1,x+1)-w;
	r--;
	int l=1,rt=r,res=r;
	while(l<=r){
		int mid=l+r>>1;
		if((rt-mid+1)*x-(sum[rt]-sum[mid-1])<=m){
			r=mid-1;
			res=mid;
		}
		else l=mid+1;
	}
	return rt-res+1;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i]; 
	sort(w+1,w+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+w[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f(w[i]));
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

5 8
0 2 5 5 10
*/