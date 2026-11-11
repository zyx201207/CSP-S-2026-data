#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500050],ans;
int cha[500050],sumbre[500050];
bool check(int mid){
	bool flag=0;
	int sum=0;
	for(int i=1;i<=mid;i++){
		sum+=sumbre[mid]-sumbre[i];
	}
	if(sum<=m) return 1;
	for(int i=2;i<=n-mid+1;i++){
		sum=sum+sumbre[i-1+mid]-sumbre[i-1]+cha[i-1]+cha[i+mid]*mid;
		if(sum<=m) return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	cha[1]=0; 
	for(int i=2;i<=n;i++) cha[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) sumbre[i]=sumbre[i-1]+cha[i];
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1; 
	}
	cout<<ans;
	return 0;
} 