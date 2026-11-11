#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+5;
int n,m;
int a[N];
bool check(int x){
	int sum=0,minn=1e15;
	for(int i=1;i<=x;i++)
		sum+=a[x]-a[i];
	minn=min(minn,sum);
	for(int i=x+1;i<=n;i++){
		sum=sum-(a[i-1]-a[i-x]);
		sum=sum+(a[i]-a[i-1])*(x-1);
		if(sum<minn) minn=sum;
	}
	return minn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	cout<<ans;
	return 0;
}