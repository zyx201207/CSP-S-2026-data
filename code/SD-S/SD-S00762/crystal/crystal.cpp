#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500010],b[500010],pre[500010];
long long n,m;
bool check(int x){
	long long mn=LONG_LONG_MAX;
	for(int i=1;i<=n-x+1;i++){
		int l=i,r=i+x-1;
		long long ans=pre[r]-pre[l-1];
		ans-=b[r]*x;
		if(ans<0)ans*=-1;
		if(ans<mn)mn=ans;
		//cout<<ans<<' ';
	}
	//cout<<mn<<endl;
	return mn<=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[n];
		pre[i]=pre[i-1]+b[i];
	}
	int l=0,r=n+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
		//cout<<l<<' '<<r<<endl;
	}
	cout<<l;
	return 0;
}
