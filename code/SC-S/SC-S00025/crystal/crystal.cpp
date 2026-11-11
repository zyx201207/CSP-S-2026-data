#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans;
long long s[500001];
int check(long long now){
	for(int i=1;i<=n;i++)s[i]=0;
	for(int i=1;i<=now;i++){
		s[now]+=a[now]-a[i];
	}
	if(s[now]<=m)return 1;
	for(int i=now+1;i<=n;i++){
		s[i]=s[i-1];
		s[i]-=a[i-1]-a[i-now];
		s[i]+=(a[i]-a[i-1])*now;
		if(s[i]<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r)>>1;
		if(check(mid)){l=mid+1;ans=mid;}
		else r=mid;
	}
	cout<<ans;
	return 0;
}