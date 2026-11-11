#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long a[N],n,ans,bns;
long long m;
bool check(long long x){
	long long s=0;
	for(int i=1;i<x;i++){
		s+=a[x]-a[i];
		if(s>m)return 0;
	}
	return 1;
}
void dfs(long long x,long long now,long long sum,long long k){
	if(now>=x)return;
	if(sum>m)return;
	bns=max(bns,k);
	dfs(x,now+1,sum+(a[x]-a[now]),k+1);
	dfs(x,now+1,sum,k);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)==1)l=mid+1,ans=mid;
		else r=mid-1;
	}
	bns=ans;
	for(int i=ans+1;i<=n;i++)
		dfs(i,0,0,1);
	cout<<bns;
	return 0;
}
