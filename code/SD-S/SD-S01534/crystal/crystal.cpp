#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,MOD=998544353;
long long INF=0x3f3f3f3f3f3f3f3f;
int n,mid,l,r;
long long m,a[N];
bool flag;
bool check(int mid){
	long long sum=INF;
	if(flag==0){
		sum=0;
		for(int i=1;i<=mid;i++)
			sum+=a[mid]-a[i];
		return sum<=m;
	} 
	for(int i=1;i<=n-mid+1;i++){
		long long cnt=0;
		for(int j=i;j<=i+mid-1;j++)
			cnt+=a[i+mid-1]-a[j];
		sum=min(sum,cnt);
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])
			flag=1;
	l=1,r=n;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
