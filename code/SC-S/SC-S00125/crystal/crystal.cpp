#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n;
long long m;
long long a[N],sum[N];
long long calc(int t,int i){
	return 1LL*a[i]*(i-t)-1LL*(sum[i-1]-sum[t-1]);
}
int findf(int L,int R){
	int l=L,r=R;
	while(l<r){
		int mid=(l+r)>>1;
		long long c=calc(mid,R+1);
		if(c<=m){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	if(a[R]>m) return R+1;
	else return r;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ans=1;
	for(int stid=2;stid<=n;stid++){
		int t=findf(1,stid-1);
//		cout<<stid<<' '<<t<<endl;
		ans=max(ans,stid-t+1);
	}
	cout<<ans<<'\n';
	return 0;
}