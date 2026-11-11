#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,mid,ans,ll,rr;
int a[500100],cha[500100],q_cha[500100],q[500100];
bool check(int x){
	int minn=LLONG_MAX;
	for(int i=x;i<=n;i++){
		ll=i-x+1,rr=i;
		minn=min(minn,q[rr]-q[ll]-(ll-1)*(q_cha[rr]-q_cha[ll]));
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		q_cha[i]=q_cha[i-1]+cha[i];
		q[i]=q[i-1]+(i-1)*cha[i];
	}
	l=1,r=n;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans;
} 
