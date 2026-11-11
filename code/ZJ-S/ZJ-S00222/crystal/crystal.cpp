#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cha[500005];
bool check(int x){
	--x;
	long long nw=0,sum=0;
	for(int i=1;i<=x;++i){
		nw=nw+i*cha[i];
		sum+=cha[i];
	}
	long long ans=nw;
	for(int i=x+1;i<n;++i){
		nw-=sum;
		sum+=cha[i];
		sum-=cha[i-x];
		nw+=cha[i]*x;
		ans=min(ans,nw);
	}
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<n;++i){
		cha[i]=a[i+1]-a[i];
	}
	int l=2,r=n+1,ans=1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid;
		}
	}
	cout<<ans;
}