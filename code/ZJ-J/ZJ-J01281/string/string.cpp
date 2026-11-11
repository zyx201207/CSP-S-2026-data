#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int a[200010];
char c[200010];
int sum[200010];
bool check(int x,int y){
	return x<=sum[y];
}
int what(int x){
	int l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(check(x,mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=sum[n];
	while(l<=r){
		int wl=what(l),wr=what(r);
		int m=min(sum[wl]-l,r-sum[wr-1]);
		m=max(m,1LL);
		if(c[wl]!=c[wr]){
			ans+=m;
		}
		l+=m;
		r-=m;
	}
	cout<<ans;
	return 0;
}