#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,inf=1000000000000000000;
int n,m,a[N];
bool check(int mid){
	int pre=0,res=inf;for(int i=1;i<=mid;i++){pre+=a[mid]-a[i];}res=min(res,pre);
	for(int l=2;l+mid-1<=n;l++){
		int r=l+mid-1;
		int now=pre-(a[r-1]-a[l-1])+(mid-1)*(a[r]-a[r-1]);
		res=min(res,now);pre=now;
	}
	return (res<=m);
}
int solve(){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){l=mid+1;ans=mid;}
		else{r=mid-1;}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	cout<<solve();
	return 0;
}