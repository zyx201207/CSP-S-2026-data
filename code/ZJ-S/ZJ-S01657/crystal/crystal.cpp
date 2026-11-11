#include<bits/stdc++.h>
using namespace std;
long long n,m,a[514514],qzh[514514],ans;
bool cheak(long long mid,long long x){
	if(a[x]*(x-mid+1)-(qzh[x]-qzh[mid-1])<=m)return true;
	else return false;
}
long long rf(long long l,long long r,long long x){
	while(l<r){
		long long mid=(l+r)/2;
		if(cheak(mid,x))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	qzh[i]=qzh[i-1]+a[i];
	for(long long i=1;i<=n;++i){
		if(a[i]==a[i+1]&&i!=n)continue;
		ans=max(ans,i-rf(1,i,i)+1);
	}
	cout<<ans;
}
