#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n;
ll m;
ll a[N],b[N],c[N],d[N]; //b[i]表示a[i]与a[i+1]的差 
//c[i]表示b[1]到b[i]的前缀和
//d[i]表示c[1]到c[i]的前缀和 
bool check(int x){
	for(int r=x;r<=n;++r){
		int l=r-x+1;
		ll sum1=c[r-1]*(r-l+1);
		ll sum2=d[r-1]-d[max(0,l-2)];
		ll sum=sum1-sum2;
		if(sum<=m){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;++i){
		b[i]=a[i+1]-a[i];
		c[i]=c[i-1]+b[i];
		d[i]=d[i-1]+c[i];
	}
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}