#include <bits/stdc++.h>
#define N 500020
#define int long long
using namespace std;
int a[N],b[N],n,m;
bool check(int x){
	for(int i=x;i<=n;i++){
		if((x*a[i]-b[i]+b[i-x])<=m) return 1;
		//cout<<(x*a[i]-b[i]+b[i-x])<<endl;
	}
	return 0;
}
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	b[0]=0;
	for(int i=1;i<=n;i++) b[i]=a[i]+b[i-1];
	int l=1,r=n,mid=0;
	//cout<<check(5000)<<endl;
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			//cout<<mid<<endl;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
